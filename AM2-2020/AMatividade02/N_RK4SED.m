%N_RK4SED  Método Númerico para resolver um SED: Runge-Kutta de ordem 4
%   [t,u,v] = N_RK4SED(f,g,a,b,n,u0,v0) Método numérico para a
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

function [t,u,v] = N_RK4SED(f,g,a,b,n,u0,v0)
    h = (b-a)/n;                                                    % Valor de cada subintervalo (passo)
    
    t = a:h:b;                                                      % Alocação de memória
    u = zeros(1, n+1);                                              % Alocação de memória
    v = zeros(1, n+1);                                              % Alocação de memória
    
    u(1) = u0;                                                      % O primeiro valor de y é sempre y0
    v(1) = v0;                                                      % O primeiro valor de y é sempre y0
    
    for i=1:n                                                       % O número de iterações vai ser igual a n
        uK1 = h*f(t(i), u(i), v(i));                                % Inclinação no início do intervalo
        vK1 = h*g(t(i), u(i), v(i));                                % Inclinação no início do intervalo
        
        uK2 = h*f(t(i) + h/2, u(i) + 0.5*uK1, v(i) + 0.5*vK1);      % Inclinação no ponto médio do intervalo
        vK2 = h*g(t(i) + h/2, u(i) + 0.5*uK1, v(i) + 0.5*vK1);      % Inclinação no ponto médio do intervalo
        
        uK3 = h*f(t(i) + h/2, u(i) + 0.5*uK2, v(i) + 0.5* vK2);     % Inclinação (novamente) no ponto médio do intervalo
        vK3 = h*g(t(i) + h/2, u(i) + 0.5*uK2, v(i) + 0.5* vK2);     % Inclinação (novamente) no ponto médio do intervalo
        
        uK4 = h*f(t(i+1), u(i) + uK3, v(i) + vK3);                  % Inclinação no final do intervalo
        vK4 = h*g(t(i+1), u(i) + uK3, v(i) + vK3);                  % Inclinação no final do intervalo
        
        uK = (uK1 + 2*uK2 + 2*uK3 + uK4)/6;                         % Cálculo da média ponderada das inclinações
        vK = (vK1 + 2*vK2 + 2*vK3 + vK4)/6;                         % Cálculo da média ponderada das inclinações
        
        u(i + 1) = u(i) + uK;                                       % Aproximação do método de RK4 para a iésima iteração
        v(i + 1) = v(i) + vK;                                       % Aproximação do método de RK4 para a iésima iteração
    end
end
