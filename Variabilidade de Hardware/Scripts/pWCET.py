import sys
import os
import numpy as np
import matplotlib.pyplot as plt
import scipy.stats 
import scipy.optimize

def main(*args):
    """
        Fits a generalized extreme value (GEV) distribution and a Gumbel distribution to experimental data,
        performs model comparison, and calculates relevant statistics. Returns a WCET value based on pWCET given.

        Arguments:
        data_file.txt : File containing the execution time data.
        block_size : Block size value for BM method.
        pWCET : Probability of Exceedence for WCET

        Example:
        python script.py sample1.txt 200 1e-9
    """

    if args[1] == '-help':
        print(main.__doc__)
    elif args[1].endswith('.txt'): # Check for valid inputs
        if os.path.exists(args[1]):
            meas_file = args[1]
            data = np.loadtxt(meas_file)
            block_size = int(args[2])
            pwcet = float(args[3])
            num_block = int(len(data)/block_size)
            new_data = []
            for i in range(num_block):
                start = i*block_size
                end = (i+1)*block_size
                new_data.append(data[start:end-1])
            bm_data = [max(block) for block in new_data]
            kernel = scipy.stats.gaussian_kde(bm_data)
            x = np.linspace(min(bm_data), max(bm_data), len(bm_data))
            pdf_data = kernel.pdf(x)
            plt.figure(figsize=(10.5, 9))
            plt.title("PDF from Block Maxima Data")
            plt.hist(bm_data, density=True, bins=50, label='Histogram', edgecolor='black')
            plt.plot(x, pdf_data, label='PDF')
            plt.xlabel("Execution Time (Clock Cycles)")
            plt.ylabel('Density')
            plt.legend(loc='upper right')
            plt.show()
            
            def gev_pdf(x, c, loc, scale):
                return scipy.stats.genextreme.pdf(x, c, loc, scale)

            i = 1
            # Fit performed by Levenberg-Marquardt Method
            while(True):
                if i == 1:
                    print('Enter a initial guess for GEV parameters:')
                    c = float(input('\t\u03BE:'))
                    loc = float(input('\t\u03BC:'))
                    scale = float(input('\t\u03C3:'))

                    initial_guess = [c, loc, scale]

                    params_gev, covariance = scipy.optimize.curve_fit(gev_pdf, x, pdf_data, 
                                                                      p0=initial_guess)
                    fitted_curve = gev_pdf(x, *params_gev)
                    plt.scatter(x, pdf_data, label='Curva Experimental')
                    plt.plot(x, fitted_curve, '--', label='Curva GEV ajustada', color='red')
                    plt.xlabel("Execution Time (Clock Cycles)")
                    plt.ylabel('Density')
                    plt.legend(loc='upper right')
                    plt.show()

                    print('===================================================================================')
                    print('GEV PARAMETERS MODEL FIT')
                    print(f'\t\u03BE: {params_gev[0]}')
                    print(f'\t\u03BC: {params_gev[1]}')
                    print(f'\t\u03C3: {params_gev[2]}\n')
                    print('===================================================================================\n')
                    i = 2
                else:
                    print('Continue with fitting? Yes [y] or No [n]?')
                    resp = input().lower()
                    if resp == 'y':
                        print('Choose another value for \u03BE.')
                        c = float(input('\t\u03BE:'))
                        
                        print('Choose another value for \u03BC.')
                        loc = float(input('\t\u03BC:'))

                        print('Choose another value for \u03C3.')
                        scale = float(input('\t\u03C3:'))

                        initial_guess = [c, loc, scale]
                        params_gev, covariance = scipy.optimize.curve_fit(gev_pdf, x, pdf_data, 
                                                                          p0=initial_guess)
                        fitted_curve = gev_pdf(x, *params_gev)
                        plt.scatter(x, pdf_data, label='Curva Experimental')
                        plt.plot(x, fitted_curve, '--', label='Curva GEV ajustada', color='red')
                        plt.legend(loc='upper right')
                        plt.xlabel("Execution Time (Clock Cycles)")
                        plt.ylabel('Density')
                        plt.show()

                        print('===================================================================================')
                        print('GEV PARAMETERS MODEL FIT')
                        print(f'\t\u03BE: {params_gev[0]}')
                        print(f'\t\u03BC: {params_gev[1]}')
                        print(f'\t\u03C3: {params_gev[2]}\n')
                        print('===================================================================================\n')
                    elif resp == 'n':
                        break
                    else:
                        print('Answer "y" or "n"')

            gev_pdf_LM = gev_pdf(x, *params_gev)
            theorical_quantiles_gev_LM = scipy.stats.genextreme.ppf(np.linspace(0.01, 0.99, 100), *params_gev)
            experimental_quantiles = np.percentile(bm_data, np.linspace(1, 99, 100))

            # Fit performed by Maximum Likelihood Estimation Method
            c, loc, scale = scipy.stats.genextreme.fit(bm_data, loc=params_gev[1], scale=params_gev[2])
            params_gev_MLE = [c, loc, scale]
            gev_pdf_MLE = gev_pdf(x, *params_gev_MLE)

            theorical_quantiles_gev_MLE = scipy.stats.genextreme.ppf(np.linspace(0.01, 0.99, 100), *params_gev_MLE)
            

            fig, axs = plt.subplots(2,2 , figsize=(10.5, 9))
            fig.suptitle('Fit Model and Quantile-Quantile Plots')
            axs[0,0].scatter(x, pdf_data, label='Experimental')
            axs[0,0].plot(x, gev_pdf_LM, '--', color = 'red', label="GEV Model LM")
            axs[0,1].scatter(theorical_quantiles_gev_LM, experimental_quantiles)
            axs[0,1].plot([np.min(theorical_quantiles_gev_LM), np.max(theorical_quantiles_gev_LM)],
                     [np.min(theorical_quantiles_gev_LM), np.max(theorical_quantiles_gev_LM)],
                     color='red', linestyle='--')
            axs[1,0].scatter(x, pdf_data, label='Experimental')
            axs[1,0].plot(x, gev_pdf_MLE, '--', color = 'red', label="GEV Model MLE")
            axs[1,1].scatter(theorical_quantiles_gev_MLE, experimental_quantiles)
            axs[1,1].plot([np.min(theorical_quantiles_gev_MLE), np.max(theorical_quantiles_gev_MLE)],
                     [np.min(theorical_quantiles_gev_MLE), np.max(theorical_quantiles_gev_MLE)],
                     color='red', linestyle='--')
            axs[0,0].legend(loc='upper right')
            axs[1,0].legend(loc='upper right')
            axs[0,0].set_ylabel('PDF')
            axs[1,0].set_xlabel('Execution Time (Clock Cycles)')
            axs[1,0].set_ylabel('PDF')
            axs[0,1].set_ylabel('Experimental Quantile')
            axs[1,1].set_xlabel('Model Quantile')
            axs[1,1].set_ylabel('Experimental Quantile')
            plt.show()


            plt.title('Comparison Between Fit Methods')
            plt.scatter(x, pdf_data, label='Curva Experimental')
            plt.plot(x, gev_pdf_LM, '--', color = 'red', label="GEV Model LM")
            plt.plot(x, gev_pdf_MLE, '--', color = 'black', label="GEV Model MLE")
            plt.xlabel("Execution Time (Clock Cycles)")
            plt.ylabel('PDF')
            plt.legend(loc='upper right')
            plt.show()


            def gumbel_pdf(x, loc, scale):
                return scipy.stats.gumbel_r.pdf(x, loc, scale)

            i = 1
            while(True):
                print('Do you want to perform a Gumbel fit? Yes [y] or No [n]?')
                answer = input().lower()
                if answer == 'y':
                    while(True):
                        if i == 1:
                            # Fit performed by Levenberg-Marquardt Method
                            print('Enter a initial guess for Gumbel parameters:')
                            loc = float(input('\t\u03BC:'))
                            scale = float(input('\t\u03C3:'))

                            initial_guess = [loc, scale]

                            params_gumbel, covariance = scipy.optimize.curve_fit(gumbel_pdf, x, pdf_data, 
                                                                                 p0=initial_guess)
                            fitted_curve = gumbel_pdf(x, *params_gumbel)
                            plt.scatter(x, pdf_data, label='Curva Experimental')
                            plt.plot(x, fitted_curve, '--', label='Curva Gumbel ajustada', color='red')
                            plt.legend(loc='upper right')
                            plt.xlabel("Execution Time (Clock Cycles)")
                            plt.ylabel('Density')
                            plt.show()

                            print('===================================================================================')
                            print('GUMBEL PARAMETERS MODEL FIT')
                            print(f'\t\u03BE: 0')
                            print(f'\t\u03BC: {params_gumbel[0]}')
                            print(f'\t\u03C3: {params_gumbel[1]}\n')
                            print('===================================================================================\n')
                            i = 2
                        else:
                            print('Continue with fitting? Yes [y] or No [n]?')
                            resp = input().lower()
                            if resp == 'y':
                                print('Choose another value for \u03BC.')
                                loc = float(input('\t\u03BC:'))
                                print('Choose another value for \u03C3.')
                                scale = float(input('\t\u03C3:'))


                                initial_guess = [loc, scale]
                                params_gumbel, covariance = scipy.optimize.curve_fit(gumbel_pdf, x, pdf_data, 
                                                                                     p0=initial_guess)
                                fitted_curve = gumbel_pdf(x, *params_gumbel)
                                plt.scatter(x, pdf_data, label='Curva Experimental')
                                plt.plot(x, fitted_curve, '--', label='Curva Gumbel ajustada', color='red')
                                plt.legend(loc='upper right')
                                plt.xlabel("Execution Time (Clock Cycles)")
                                plt.ylabel('Density')
                                plt.show()

                                print('===================================================================================')
                                print('GUMBEL PARAMETERS MODEL FIT')
                                print(f'\t\u03BE: 0')
                                print(f'\t\u03BC: {params_gumbel[0]}')
                                print(f'\t\u03C3: {params_gumbel[1]}\n')
                                print('===================================================================================\n')
                            elif resp == 'n':
                                break
                            else:
                                print('Answer "y" or "n"')

                    gumbel_pdf_LM = gumbel_pdf(x, *params_gumbel)

                    theorical_quantiles_gumbel_LM = scipy.stats.gumbel_r.ppf(np.linspace(0.01, 0.99, 100), *params_gumbel)

                    # Fit performed by Maximum Likelihood Estimation Method
                    loc, scale = scipy.stats.gumbel_r.fit(bm_data, loc=params_gumbel[0], scale=params_gumbel[1])
                    params_gumbel_MLE =  [loc, scale]
                    gumbel_pdf_MLE = gumbel_pdf(x, *params_gumbel_MLE)

                    theorical_quantiles_gumbel_MLE = scipy.stats.gumbel_r.ppf(np.linspace(0.01, 0.99, 100), *params_gumbel_MLE)

                    fig, axs = plt.subplots(2,2 , figsize=(10.5, 9))
                    fig.suptitle('Fit Model and Quantile-Quantile Plots')
                    axs[0,0].scatter(x, pdf_data, label='Experimental')
                    axs[0,0].plot(x, gumbel_pdf_LM, '--', color = 'red', label="Gumbel Model LM")
                    axs[0,1].scatter(theorical_quantiles_gumbel_LM, experimental_quantiles)
                    axs[0,1].plot([np.min(theorical_quantiles_gumbel_LM), np.max(theorical_quantiles_gumbel_LM)],
                             [np.min(theorical_quantiles_gumbel_LM), np.max(theorical_quantiles_gumbel_LM)],
                             color='red', linestyle='--')
                    axs[1,0].scatter(x, pdf_data, label='Experimental')
                    axs[1,0].plot(x, gumbel_pdf_MLE, '--', color = 'red', label="Gumbel Model MLE")
                    axs[1,1].scatter(theorical_quantiles_gumbel_MLE, experimental_quantiles)
                    axs[1,1].plot([np.min(theorical_quantiles_gumbel_MLE), np.max(theorical_quantiles_gumbel_MLE)],
                             [np.min(theorical_quantiles_gumbel_MLE), np.max(theorical_quantiles_gumbel_MLE)],
                             color='red', linestyle='--')
                    axs[0,0].legend(loc='upper right')
                    axs[1,0].legend(loc='upper right')
                    axs[0,0].set_ylabel('PDF')
                    axs[1,0].set_xlabel('Execution Time (Clock Cycles)')
                    axs[1,0].set_ylabel('PDF')
                    axs[0,1].set_ylabel('Experimental Quantile')
                    axs[1,1].set_xlabel('Model Quantile')
                    axs[1,1].set_ylabel('Experimental Quantile')
                    plt.show()


                    plt.title('Comparison Between Fit Methods')
                    plt.scatter(x, pdf_data, label='Curva Experimental')
                    plt.plot(x, gumbel_pdf_LM, '--', color = 'red', label="Gumbel Model LM")
                    plt.plot(x, gumbel_pdf_MLE, '--', color = 'black', label="Gumbel Model MLE")
                    plt.xlabel("Execution Time (Clock Cycles)")
                    plt.ylabel('PDF')
                    plt.legend(loc='upper right')
                    plt.show()
                    
                    break
                elif answer == 'n':
                    break
                else:
                    print('Answer "y" or "n"')

            #fitting Gumbel model

            def difference_function(t, shape, loc, scale, target_probability):
                return scipy.stats.genextreme.cdf(t, shape, loc, scale) - (1 - target_probability)

            def find_wcet(target_probability, params_gev):
                result = scipy.optimize.root_scalar(difference_function, args=(params_gev[0], 
                                                                               params_gev[1], 
                                                                               params_gev[2], 
                                                                               target_probability), 
                                                                               bracket=[0, 1e10])
                
                return result.root


            wcet_gev_LM = find_wcet(pwcet, params_gev)
            wcet_gev_MLE = find_wcet(pwcet, params_gev_MLE)

            print('===================================================================================')
            print('GEV PARAMETERS MODEL FIT - LM')
            print(f'\t\u03BE: {params_gev[0]}')
            print(f'\t\u03BC: {params_gev[1]}')
            print(f'\t\u03C3: {params_gev[2]}\n')
            print (f'pWCET = {pwcet}')
            print(f'WCET = {wcet_gev_LM}')
            print('===================================================================================\n')

            print('===================================================================================')
            print('GEV PARAMETERS MODEL FIT - MLE')
            print(f'\t\u03BE: {params_gev_MLE[0]}')
            print(f'\t\u03BC: {params_gev_MLE[1]}')
            print(f'\t\u03C3: {params_gev_MLE[2]}\n')
            print (f'pWCET = {pwcet}')
            print(f'WCET = {wcet_gev_MLE}')
            print('===================================================================================\n')

            if answer == 'y':
                wcet_gumbel_LM = find_wcet(pwcet, [0, *params_gumbel])
                wcet_gumbel_MLE = find_wcet(pwcet, [0, *params_gumbel_MLE])

                print('===================================================================================')
                print('GUMBEL PARAMETERS MODEL FIT - LM')
                print(f'\t\u03BE: 0')
                print(f'\t\u03BC: {params_gumbel[0]}')
                print(f'\t\u03C3: {params_gumbel[1]}\n')
                print (f'pWCET = {pwcet}')
                print(f'WCET = {wcet_gumbel_LM}')
                print('===================================================================================\n')

                print('===================================================================================')
                print('GUMBEL PARAMETERS MODEL FIT - MLE')
                print(f'\t\u03BE: 0')
                print(f'\t\u03BC: {params_gumbel[0]}')
                print(f'\t\u03C3: {params_gumbel[1]}\n')
                print (f'pWCET = {pwcet}')
                print(f'WCET = {wcet_gumbel_MLE}')
                print('===================================================================================\n')

            else:
                pass
        
        else:
            raise FileNotFoundError("File .txt does not exist.")
    else:
        raise SyntaxError("1st and 2nd args must be valids .txt files.")

if __name__ == "__main__":
    main(*sys.argv)
