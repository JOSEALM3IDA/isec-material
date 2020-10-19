%PEDIRDADOS Pede dados do PVI ao utilizador
% 
%INPUT: 
%   Nada
%
%OUTPUT: 
%   strF - Função em x e y em formato string, para uso noutras funçoes
%   f - Função em x e y da equação diferencial
%   a - Limite esquerdo do intervalo
%   b - Limite direito do intervalo
%   n - Numero de sub-intervalos
%   y0 - Valor (condição) Inicial do PVI
%
%   07/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   04/03/2020 - José Almeida .: a2019129077@isec.pt
%   07/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function [strF, f, a, b, n, y0] = pedirDados()
    disp('--------------Dados PVI----------------')


    while(1)
        strF = input('f(t,y) = ','s');                              % entrada do tipo STRING
        f = @(t,y) eval(vectorize(strF));

        try                                                         % o try serve para apanhar possiveis erros no input do user
            syms t y;                                               % declarar variaveis symbolic (math symbols)
            fTeste = f(t,y);                                        % faz um teste à função para verifica se está em ordem a t e y
            break;
        catch isec % nome de variável, neste caso nao interessa
            errordlg('Introduza uma função em t e y!', 'ERRO', 'modal');    % Abre uma mensage de erro
        end 
    end

    while(1)
        a = str2num(input('a = ', 's'));                            % limite inferior do intervalo

        if(isscalar(a) && isreal(a))                                % Se 'a' for um número real, sai do ciclo
            break;
        else
            errordlg('Introduza um valor real para a!', 'ERRO', 'modal'); % abre uma error box
        end
    end

    while(1)
        b = str2num(input('b = ', 's'));                            % limite superior do intervalo

        if(isscalar(b) && isreal(b) && a < b)                       % Se 'b' for um número real e se for maior que a, sai do ciclo
            break;
        elseif (a >= b)                                             % Se 'a' for maior ou igual a b, entra no ciclo
            errordlg('Por favor introduza b tal que b > a!','ERRO','modal');    % Abre uma mensagem de erro
        else
            errordlg('Introduza um numero b real!', 'ERRO', 'modal');   % Abre uma mensagem de erro
        end
    end

    while(1)
        n = str2num(input('n = ', 's'));                                % Recebe o valor de n

        if(isscalar(n) && (mod(n,1) == 0) && n > 0)                     % Se for um número, se for par e se for maior que 0, entra no ciclo
            break;
        else
            errordlg('Introduza n inteiro e maior que zero!', 'ERRO', 'modal');     % Abre uma mensagem de erro
        end
    end

    while(1)
        y0 = str2num(input('y0 = ', 's'));                              % Recebe o valor de y0

        if(isscalar(y0) && isreal(y0))                                  % Se for um número real, entra no ciclo
            break;
        else
            errordlg('Introduza o valor inicial!', 'ERRO', 'modal');    % Abre uma mensagem de erro
        end
    end
    fprintf('\n')                                                       % Muda de linha