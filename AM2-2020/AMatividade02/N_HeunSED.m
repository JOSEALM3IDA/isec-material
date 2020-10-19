%N_HeunSED  Método Númerico para resolver um SED: Heun (Euler melhorado)
%   [t,u,v] = N_HeunSED(f,g,a,b,n,u0,v0) Método numérico para a
%   resolução de um SED (ordem 2)
%   u'= f(t,u,v), v'=g(t,u,v), t=[a, b], u(a)=u0 e v(a)=v0  
%
%INPUT:
%   f, g - funções do 2.º membro das Equações Diferenciais
%   [a, b] - extremos do intervalo da variável independente t
%   n - número de subintervalos ou iterações do método
%   u0, v0 - condições iniciais t=a -> u=u0 e v=v0
%
%OUTPUT: 
%   [t,u,v] - vector das soluções aproximações e da discretização de t
%
%   04/05/2020 - Carlos Pais .: a2010017171@isec.pt
%   04/05/2020 - José Almeida .: a2019129077@isec.pt
%   04/05/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function [t,u,v] = N_HeunSED(f,g,a,b,n,u0,v0)
    h = (b-a)/n;                                       % Valor de cada subintervalo (passo)
    
    t = a:h:b;                                         % Alocação de memória
    u = zeros(1, n+1);                                 % Alocação de memória
    v = zeros(1, n+1);                                 % Alocação de memória
   
    u(1) = u0;                                         % O primeiro valor de u é sempre u0
    v(1) = v0;                                         % O primeiro valor de v é sempre v0
    
    for i=1:n                                          % O número de iterações vai ser igual a n
        uK1 = f(t(i),u(i),v(i));                       % Inclinação no início do intervalo
        vK1 = g(t(i),u(i),v(i));                       % Inclinação no início do intervalo
        
        uK2 = f(t(i+1), u(i) + uK1*h, v(i) + vK1*h);   % Inclinação no fim do intervalo
        vK2 = g(t(i+1), u(i) + uK1*h, v(i) + vK1*h);   % Inclinação no fim do intervalo  
        
        uK = 0.5*(uK1 + uK2);                          % Cálculo da média das inclinações
        vK = 0.5*(vK1 + vK2);                          % Cálculo da média das inclinações
        
        u(i + 1) = u(i) + h*uK;                        % Aproximação do método de Heun para a iésima iteração
        v(i + 1) = v(i) + h*vK;                        % Aproximação do método de Heun para a iésima iteração
    end
end