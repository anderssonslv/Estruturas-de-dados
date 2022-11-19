def convert(string):
    str2 = [];
    for i in range (0,len(string)):
            if i%2 == 0:
                print(i)
                str2.append(string[i].join(['"','"']))
    str3 = ",".join(str2)
    return str3;

def salva(string):
    with open ('arq.txt','w') as arquivo:
        arquivo.write(string)