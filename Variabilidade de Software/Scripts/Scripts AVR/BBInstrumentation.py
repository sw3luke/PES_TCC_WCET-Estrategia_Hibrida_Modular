import re



def extract_basic_blocks(file_path):

    basic_blocks = []

    current_block = None



    with open(file_path, 'r') as file:

        lines = file.readlines()



        for index, line in enumerate(lines):

            if line.startswith("Basic Block"):

                if current_block is not None:

                    basic_blocks.append(current_block)

                print(index+1)

                current_block = {'function': line.strip().split(' ')[2], 'begin': lines[index+1].strip(), 'end': None}

            elif current_block is not None and line.strip():

                current_block['end'] = line.strip()



        if current_block is not None:

            basic_blocks.append(current_block)



    return basic_blocks



file_path = "binarySearchPython_alf_to_C_identified_full.txt"

basic_blocks = extract_basic_blocks(file_path)



file1 = open('bs.c', 'r')

file1Lines = file1.readlines()



visitedLines = []

whilePattern = r'\bwhile\s*\(\s*.*\s*\)'

for index, block in enumerate(basic_blocks):



    if(block['begin'][-1] != '}'): #falso quando se trata do fechamento de um loop

        print(block['begin'])

        lineIndexes = list(re.search('bb[0-9]{1,3} Line [0-9]{1,10} ', block['begin']).span()) #Transform tuple in array

        treatingLine = block['begin'][lineIndexes[0]:lineIndexes[1]]

        treatingLine = treatingLine.split(' Line ')

        #print(file1Lines[int(treatingLine[1])-2])

        if((int(treatingLine[1]) - 1) in visitedLines):

            continue

        visitedLines.append((int(treatingLine[1]) - 1))

        if(file1Lines[int(treatingLine[1])-2].find("else") == -1):



            file1Lines[int(treatingLine[1]) - 1] = '\

            \nStartTickCounter();\n' + file1Lines[int(treatingLine[1]) - 1]

        # elif(re.search(whilePattern,file1Lines[int(treatingLine[1])-2]) == True):

        #     print('deixar vazio por enquanto')

        else:

            if(block['end'] != None):





                file1Lines[int(treatingLine[1]) - 1] = '\

                \nStopTickCounter();\n\

                ResetTickCounter();\n\

                StartTickCounter();\n' + file1Lines[int(treatingLine[1]) - 1]

            else:

                print('entrei')

                indexes= list(re.search("bb[0-9]{1,10}b", block['begin']).span())

                file1Lines[int(treatingLine[1]) - 1] = '\

                \nStopTickCounter();\n\

                ResetTickCounter();\n\

                StartTickCounter();\n' + file1Lines[int(treatingLine[1]) - 1]







    if(block['end'] != None):

        if(block['begin'][-1] == '}' and block['end'][-1] == '}'):

            lineIndexes = list(re.search('Line [0-9]{1,10} ', block['end']).span()) #Transform tuple in array

            treatingLine = block['end'][lineIndexes[0]:lineIndexes[1]]

            treatingLine = treatingLine.split('Line ')

            file1Lines[int(treatingLine[1]) - 1] = '\

            \nStopTickCounter();\n\

            ResetTickCounter();\n\

            printf("' + block["function"] +'::'+ block['end'].split('::')[0] + ' 0\\r\\n");\n\

            StartTickCounter();' + file1Lines[int(treatingLine[1]) - 1]

            

        elif(block['end'][-1] == '}'):

            lineIndexes = list(re.search('Line [0-9]{1,10} ', block['end']).span()) #Transform tuple in array

            treatingLine = block['end'][lineIndexes[0]:lineIndexes[1]]

            treatingLine = treatingLine.split('Line ')

            file1Lines[int(treatingLine[1]) - 1] = '\

            \nStopTickCounter();\n\

            printf("' + block["function"] +'::' + block['end'].split('::')[0] + ' %u\\r\\n", GetTicks());\n\

            ResetTickCounter();\n' + file1Lines[int(treatingLine[1]) - 1]

        elif('::' not in block['end']):

            lineIndexes = list(re.search('Line [0-9]{1,10} ', block['end']).span()) #Transform tuple in array

            treatingLine = block['end'][lineIndexes[0]:lineIndexes[1]]

            treatingLine = treatingLine.split('Line ')

            file1Lines[int(treatingLine[1]) - 1] = file1Lines[int(treatingLine[1]) - 1] + '\

            \nStopTickCounter();\n\

            printf("' + block["function"] +'::' + block['end'].split(' ')[0] + ' %u\\r\\n", GetTicks());\n\

            ResetTickCounter();\n'

        else:

            lineIndexes = list(re.search('Line [0-9]{1,10} ', block['end']).span()) #Transform tuple in array

            treatingLine = block['end'][lineIndexes[0]:lineIndexes[1]]

            treatingLine = treatingLine.split('Line ')

            file1Lines[int(treatingLine[1]) - 1] = file1Lines[int(treatingLine[1]) - 1] + '\

            \nStopTickCounter();\n\

            printf("' + block["function"] +'::' + block['end'].split('::')[0] + ' %u\\r\\n", GetTicks());\n\

            ResetTickCounter();\n'

    

    else:

        indexes= list(re.search("bb[0-9]{1,10}b", block['begin']).span())

        file1Lines[int(treatingLine[1]) - 1] = file1Lines[int(treatingLine[1]) - 1] +'\

        \nStopTickCounter();\n\

        printf("' + block["function"] +'::' + block['begin'][indexes[0]:indexes[1]-1] + ' %u\\r\\n", GetTicks());\n\

        ResetTickCounter();\n\

        StartTickCounter();\n'







file2 = open('binarySearchInstrumentado.c', 'w')

file2.writelines(file1Lines)