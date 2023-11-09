import sys 
import os
import csv

def main(*args):
    """
    This code has 2 main functionalities:
        - To make a correspondence between .alf BB code and a .c BB code;
        - To give the WCEP (Worst Case Execution Path) given a .alf path to the corresponding
        instruction in .c code.

    Arguments (*args):
        - map_path : The absolute path of a map file (file with ALF Basic Blocks and the
        corresponding line and column of C instructions (.map);
        - c_path : The absolute path of a C file (.c);
        - -o : Output format file (.txt/.csv). If not passed, by default, -o=.txt;
        - -c : Simplified Correspondence between .alf BB code and a .c BB code. If this flag is passed,
        -f flag must not be passed;
        - -f : Full Correspondence between .alf BB code and a .c BB code. If this flag is passed,
        -c flag must not be passed;
        - -p (optional) : Worst Path with C instructions;
        - AE_path (optional) : The absolute path of a text file with the WCEP info. If -p flag is raised,
        AE_path must be given.
    """

    if len(args) < 4 and len(args) > 2:
        raise SyntaxError("Insufficient arguments.")
    elif len(args) > 7:
        raise SyntaxError("Too many arguments were given. For help instructions, insert -help as 1st argument.")
    else:
        if args[1] == '-help':
            print(main.__doc__)
        elif args[1].endswith('.map'): # Check for valid input files
            if os.path.exists(args[1]):
                filename_map = args[1]
                if args[2].endswith('.c'):
                    if os.path.exists(args[2]):
                        filename_code = args[2]
                        k = None
                        for arg in args:
                            k_v = arg.split("=")
                            if len(k_v) == 2: 
                                k = k_v[0]
                                v = k_v[1]
                        if not k:
                            file_ext = '.txt'
                        elif k == '-o':
                            file_ext = v
                        else:
                            raise SyntaxError("Wrong Flag parameter was given.")
                        

                        file_map = open(filename_map, 'r')
                        file_code = open(filename_code, 'r')
                        with file_map as f1:
                            lines_fmap = f1.readlines()
                        f1.close()
                        with file_code as f2:
                            lines_fcode = f2.readlines()
                        f2.close()
                        basic_blocks = []
                        for line in lines_fmap:
                            line = line.split(';')
                            single_bb = line[0].split('::')
                            basic_blocks.append(single_bb)
                            basic_blocks[-1].append(int(line[-2])-1)
                        for i in range(len(basic_blocks)):
                            if (basic_blocks[i][1] == 'bb'):
                                basic_blocks[i][1] = 'bb0'
                        def criteria1(e):
                            return int(e[1][2:])
                        def criteria2(e):
                            return e[0]
                        basic_blocks.sort(key=criteria1)
                        basic_blocks.sort(key=criteria2)
                        bb_text = []    
                        bb_text.append('Basic Blocks in C code \n')
                        alf_line = []
                        for bb in basic_blocks:
                            if len(bb) == 3:
                                alf_line.append(bb[1])
                            else:
                                n = len(bb)
                                alf_line.append('::'.join(bb[1:n-1]))
                        
                        if (not '-c' in args) and (not '-f' in args):
                            if not '-p' in args:
                                raise SyntaxError("-c, -f or -p flag must be selected.")
                           

                        elif ('-c' in args) and (not '-f' in args):
                            print("Simplified Correspondence is in execution...\n")
                            print('Basic Blocks in C code \n')
                            for i in range(len(basic_blocks)):
                                if i == 0: 
                                    print(f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}')
                                    print(f'Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')
                                    bb_text.append(f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}\n')
                                    bb_text.append(f'Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')
                                else:
                                    if ((basic_blocks[i][1] == basic_blocks[i-1][1]) and (basic_blocks[i][0] == basic_blocks[i-1][0])):
                                        print(f'Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')
                                        bb_text.append(f'Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')
                                    else:
                                        print(f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}')
                                        print(f'Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')
                                        bb_text.append(f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}\n')
                                        bb_text.append(f'Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')

                            filename = filename_code[:-2]
                            filename += '_alf_to_C_identified_simpl' + file_ext

                            if file_ext == '.txt':

                                file_save = open(filename, 'w')

                                with file_save as f3:
                                    for line in bb_text:
                                        f3.writelines(line)
                                f3.close()
                            elif file_ext == '.csv':
                                bb_text_csv = []
                                for i in range(len(basic_blocks)):
                                    if i == 0: 
                                        bb_text_csv.append([f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}'])
                                        bb_text_csv.append(['Line', basic_blocks[i][-1] + 1, lines_fcode[basic_blocks[i][-1]]])
                                    else:
                                        if ((basic_blocks[i][1] == basic_blocks[i-1][1]) and (basic_blocks[i][0] == basic_blocks[i-1][0])):
                                            bb_text_csv.append(['Line', basic_blocks[i][-1] + 1, lines_fcode[basic_blocks[i][-1]]])
                                        else:
                                            bb_text_csv.append([f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}'])
                                            bb_text_csv.append(['Line', basic_blocks[i][-1] + 1, lines_fcode[basic_blocks[i][-1]]])
                                
                                with open(filename, 'w', newline='') as f:
                                    
                                    write = csv.writer(f, delimiter=';')
                                    write.writerows(bb_text_csv)

                                f.close()
                            
                            else:
                                raise SyntaxError("Save file must be a .txt or .csv.")

                            return print("Simplified Correspondence Finished")

                        elif (not '-c' in args) and ('-f' in args):
                            print("Full Correspondence is in execution...")


                            print('Basic Blocks in C code \n')

                            for i in range(len(basic_blocks)):
                                if i == 0: 
                                    print(f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}')
                                    print(f'{alf_line[i]} Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')
                                    bb_text.append(f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}\n')
                                    bb_text.append(f'{alf_line[i]} Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')
                                else:
                                    if ((basic_blocks[i][1] == basic_blocks[i-1][1]) and (basic_blocks[i][0] == basic_blocks[i-1][0])):
                                        print(f'{alf_line[i]} Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')
                                        bb_text.append(f'{alf_line[i]} Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')
                                    else:
                                        print(f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}')
                                        print(f'{alf_line[i]} Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')
                                        bb_text.append(f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}\n')
                                        bb_text.append(f'{alf_line[i]} Line {basic_blocks[i][-1] + 1} {lines_fcode[basic_blocks[i][-1]]}')

                            filename = filename_code[:-2]
                            filename += '_alf_to_C_identified_full' + file_ext

                            if file_ext == '.txt':

                                file_save = open(filename, 'w')

                                with file_save as f4:
                                    for line in bb_text:
                                        f4.writelines(line)
                                f4.close()

                            elif file_ext == '.csv':
                                bb_text_csv = []
                                for i in range(len(basic_blocks)):
                                    if i == 0: 
                                        bb_text_csv.append([f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}'])
                                        bb_text_csv.append([alf_line[i], 'Line', basic_blocks[i][-1] + 1, lines_fcode[basic_blocks[i][-1]]])
                                    else:
                                        if ((basic_blocks[i][1] == basic_blocks[i-1][1]) and (basic_blocks[i][0] == basic_blocks[i-1][0])):
                                            bb_text_csv.append([alf_line[i], 'Line', basic_blocks[i][-1] + 1, lines_fcode[basic_blocks[i][-1]]])
                                        else:
                                            bb_text_csv.append([f'Basic Block {basic_blocks[i][0]} {basic_blocks[i][1]}'])
                                            bb_text_csv.append([alf_line[i], 'Line', basic_blocks[i][-1] + 1, lines_fcode[basic_blocks[i][-1]]])
                                

                                with open(filename, 'w', newline='') as f:
                                    
                                    write = csv.writer(f, delimiter=';')
                                    write.writerows(bb_text_csv)

                                f.close()
                            else:
                                raise SyntaxError("Save file must be a .txt or .csv.")

                            return print("Full Correspondence Finished")         
                        else:
                            raise SyntaxError("Only one flag (-f or -c) must be given.")
                        
                        if '-p' in args:
                            if args[-1] == '-p':
                                raise SyntaxError("AE_path must be given.")
                            else:
                                if args[-1].endswith('.txt'):
                                    if os.path.exists(args[-1]):
                                        print("WCEP is in execution...")
                                        filename_AE = args[-1]
                                        file_ae = open(filename_AE, 'r')
                                        words = "WCET path based on BB cost lookup table:"
                                        wcet_path = []
                                        with file_ae as f:
                                            lines_wcet = f.readlines()
                                            for line in lines_wcet:
                                                if line.find(words) != -1:
                                                    line = line.split(' ')
                                                    wcet_path.append(line)
                                        f.close()
                                        words = words.split(' ')
                                        wcet_path = wcet_path[0]
                                        for word in words:
                                            wcet_path.remove(word)
                                        wcet_path.pop()

                                        bb_wcep = []

                                        for line in wcet_path:
                                            single_bb = line.split('::')
                                            bb_wcep.append(single_bb)

                                        for i in range(len(bb_wcep)):
                                            if (bb_wcep[i][1] == 'bb'):
                                                bb_wcep[i][1] = 'bb0'            

                                        for i in range(len(bb_wcep)):
                                            if len(bb_wcep[i]) > 2:
                                                x = '::'.join(bb_wcep[i][1:])
                                                while len(bb_wcep[i]) > 1:
                                                    bb_wcep[i].pop() 
                                                bb_wcep[i].append(x)


                                        bb_map = []
                                        for i in range(len(basic_blocks)):
                                            if i == 0: 
                                                bb_map.append([basic_blocks[i][0], alf_line[i], lines_fcode[basic_blocks[i][-1]]])
                                            else:
                                                if ((basic_blocks[i][1] == basic_blocks[i-1][1]) and (basic_blocks[i][0] == basic_blocks[i-1][0])):
                                                    bb_map.append([basic_blocks[i][0], alf_line[i], lines_fcode[basic_blocks[i][-1]]])
                                                else:
                                                    bb_map.append([basic_blocks[i][0], alf_line[i], lines_fcode[basic_blocks[i][-1]]])


                                        wcep_c = []
                                        for bb_wcep_item in bb_wcep:
                                            for bb_map_item in bb_map:
                                                if bb_wcep_item[0] == bb_map_item[0]:
                                                    if bb_wcep_item[1] == bb_map_item[1]:
                                                        wcep_c.append([bb_wcep_item[0], bb_wcep_item[1], bb_map_item[-1]])


                                        filename = filename_code[:-2] + '_wcep.txt'
                                        file_save = open(filename, 'w')

                                        with open(filename, 'w') as f5:
                                            for line in wcep_c:
                                                f5.writelines(line)
                                        f5.close()

                                        return print("WCEP Finished")
                                    else:
                                        raise FileNotFoundError('The specified file does not exist.')
                                else:
                                    raise SyntaxError("Last arg must be a valid .txt file.")
            
                    else:
                        raise FileNotFoundError("File .c does not exist.")
                else:
                    raise SyntaxError("2nd arg must be a valid .c file.")
            else:
                raise FileNotFoundError("File .map does not exist.")
        else:
            raise SyntaxError("1st arg must be a valid .map file.")

if __name__ == "__main__":
    main(*sys.argv)
