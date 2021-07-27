function [ fis_gorjeta ] = aula_gorjeta()

%PASSO 1: crie a estrutura FIS de nome fis_gorjeta
fis_gorjeta = newfis('gorjeta');

%PASSO 2: criar variaveis linguisticas 'servico', 'comida' e 'gorjeta'
fis_gorjeta=addvar(fis_gorjeta,'input','servico',[0 10]);
fis_gorjeta=addvar(fis_gorjeta,'input','comida',[0 10]);
fis_gorjeta=addvar(fis_gorjeta,'output','gorjeta',[0 30]);

%PASSO 3: funcoes de pertenca para cada variavel criada anteriormente
fis_gorjeta=addmf(fis_gorjeta,'input',1,'fraco','gaussmf',[1.5 0]);
fis_gorjeta=addmf(fis_gorjeta,'input',1,'bom','gaussmf',[1.5 5]);
fis_gorjeta=addmf(fis_gorjeta,'input',1,'excelente','gaussmf',[1.5 10]);

fis_gorjeta=addmf(fis_gorjeta,'input',2,'ma','trapmf',[0 0 1 3]);
fis_gorjeta=addmf(fis_gorjeta,'input',2,'deliciosa','trapmf',[0 0 1 3]);
 
fis_gorjeta=addmf(fis_gorjeta,'output',1,'fraca','trimf',[0 5 10]);
fis_gorjeta=addmf(fis_gorjeta,'output',1,'media','trimf',[10 15 20]);
fis_gorjeta=addmf(fis_gorjeta,'output',1,'generosa','trimf',[20 25 30]);
 
%PASSO 4: criar matriz de regras e adicionar com addrule

regras=[1 1 1 1 2;
        2 0 2 1 2;
        3 2 3 1 2];
    
fis_gorjeta=addrule(fis_gorjeta, regras);


%PASSO 5: avaliar para varios valores de service e comida com evalfis
for servico=0:10
    for comida=0:10
        entrada=[servico comida];
        out = evalfis(entrada,fis_gorjeta);
        fprintf('servico = %d\nComida = %d\nGorjeta = %f\n\n',servico, comida, out);
    end
end
 
end
