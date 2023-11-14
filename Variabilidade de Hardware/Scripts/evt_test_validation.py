import sys
import os
import scipy.stats as stat
import numpy as np 
from statsmodels.sandbox.stats import runs
from statsmodels.stats import diagnostic
from statsmodels.api import tsa
import matplotlib.pyplot as plt 



def main(*args):
    """
        Perform tests to validate if the provided data are 
        Independent and Identically Distributed (I.I.D.).

        Usage:
        python script.py data_file_1.txt 2 [-plt]

        Arguments:
        data_file_1.txt : File containing the data for the total data sample.
        nr_samples : number of samples to divide total data.
        -plt (optional)  : If provided, plots the ARIMA (Autoregressive Integrated Moving Average) adjustment graphs.

        Tests Performed:
        1. Anderson-Darling K-Sample Test for two-sample distribution comparison.
        2. Wald Wolfowitz Runs Test for randomness of observed values.
        3. Ljung-Box Test on residuals for independence of residuals.
        4. Kolmogorov-Smirnov Test for two-sample distribution comparison.

        Example:
        python script.py sample1.txt 2 -plt
    """


    if args[1] == '-help':
        print(main.__doc__)
    elif args[1].endswith('.txt'): # Check for valid inputs
        if os.path.exists(args[1]):
            meas_file = args[1]
            data = np.loadtxt(meas_file)
            nr_sample = int(args[2])

            sample_size = int(len(data)/nr_sample)
            alpha = 0.05
            sample_data = []
            for i in range(nr_sample):
                start = i*sample_size
                end = (i+1)*sample_size
                sample_data.append(data[start:end-1])

            print("=============================================================================================================================")
            print(f"I.I.D. TESTS FOR SAMPLE ({meas_file})")
            print("=============================================================================================================================")

            # Kolmogorov-Smirnov Test

            ks_test = stat.ks_2samp(data[:len(data)//2], data[len(data)//2:], method='auto')
            
            print("Kolmogorov-Smirnov Test for 2 random samples")
            print("P-Value", ks_test.pvalue)
            if ks_test.pvalue >= alpha:
                print('The null hypothesis of the two samples being drawn from the same distribution cannot be rejected at a significance level of ', alpha)
            else:
                print('The null hypothesis of the two samples being drawn from the same distribution is rejected at a significance level of ', alpha)

            print("-----------------------------------------------------------------------------------------------------------------------------")

            # Anderson-Darling K-Samples test for different distributions
            ad_test = stat.anderson_ksamp(sample_data, midrank=True)
            print("Anderson-Darling K-Samples Test")
            print("P-Value", ad_test.pvalue)
            if ad_test.pvalue >= alpha:
                print('The null hypothesis that the two random samples come from the same distribution cannot be rejected at a significance level of ', alpha)
            else:
                print('The null that the two random samples come from the same distribution is rejected at a significance level of ', alpha)
            print("-----------------------------------------------------------------------------------------------------------------------------")

            # Wald Wolfowitz Runs Test

            ww_test = runs.runstest_1samp(data)
            print('Wald Wolfowitz Runs Test')
            print("P-Value", ww_test[1])
            if ww_test[1] >= alpha:
                print('The null hypothesis of observed value randomness cannot be rejected at a significance level of ', alpha)
            else:
                print('The null hypothesis of observed value randomness is rejected at a significance level of ', alpha)

            print("-----------------------------------------------------------------------------------------------------------------------------")
            # Ljung-Box Test
            # Ljung-Box test must be done in residual data
            adjust = tsa.ARIMA(data, order=(1,1,1)).fit()
            res = adjust.resid
            lb_test = diagnostic.acorr_ljungbox(res, boxpierce=True, return_df=True, auto_lag=True)
            pvalue = lb_test['lb_pvalue'].values[-1:]

            print('Ljung-Box Test')
            print("P-Value: ", pvalue)
            if pvalue >= alpha:
                print('The null hypothesis of residuals are independently distributed cannot be rejected at a significance level of ', alpha)
            else:
                print('The null hypothesis of residuals are independently distributed is rejected at a significance level of ', alpha)
            

            if args[-1] == "-plt":
                plt.figure(figsize=(10.5, 9))
                plt.plot(data, linestyle='--', marker='o', color = 'blue', markersize = 4)
                plt.plot(adjust.fittedvalues, linestyle='--', marker='o', color = 'red', markersize = 4)
                plt.legend(['Dados Amostra 1','Curva de Ajuste ARIMA Model (1,1,1)'], fontsize=14)
                plt.show()  
        else:
            raise FileNotFoundError("File .txt does not exist.")
    else:
        raise SyntaxError("1st and 2nd args must be valids .txt files.")

if __name__ == "__main__":
    main(*sys.argv)
