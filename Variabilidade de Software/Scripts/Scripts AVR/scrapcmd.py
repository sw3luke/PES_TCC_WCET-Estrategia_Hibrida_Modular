import pexpect



#Essa funcao sera utilizada para gerar o .elf necessario para a execucao no simulAVR

#caso optemos por realizar a instrumentacao atraves de um llvm pass sera necessario dividir as etapas nessa funcao

def generateDotElfFile(command): 

    processElf = pexpect.spawn(command)

    return



def getCMDOutput(command):

    try:

        process = pexpect.spawn(command) #inicio um cmd nesse diretorio e executo o comando expecificado

        process.expect(pexpect.EOF)  #espera chegar no EOF(end of file)

        output = process.before.decode()  # Pego o output gerado do processo

        return output

    except Exception as e:

        return f"deu ruim =(: {e}"



#Depois lembrar de parametrizar o nome do arquivo

#generateElfCommand = "avr-gcc -std=c89 -pedantic -mmcu=atmega328 -o test.elf binarySearch.c avr-tick-counter.S"

cmdCommand = "simulavr -d atmega328 -f binarySearchInstrumentado.elf -W 0x20,- -T exit" #comando que vai ser executado e tera output capturado

#generateDotElfFile(generateElfCommand)

output = getCMDOutput(cmdCommand)



f = open("BBTimeMeasure.txt", "a")

f.write(output)

f.close()