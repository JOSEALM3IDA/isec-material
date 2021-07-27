function [ fis ] = controlador()

fis = newfis('chuveiro');

fis = addvar(fis, 'input', 'temperatura', [-5 50]);
fis = addvar(fis, 'input', 'fluxo', [-1 1]);
fis = addvar(fis, 'output', 't-fria', [-1 1]);
fis = addvar(fis, 'output', 't-quente', [-1 1]);

fis = addmf(fis, 'input', 1, 'fria', 'trapmf', [-10 -5.5 5 20]);
fis = addmf(fis, 'input', 1, 'ok', 'trimf', [15 30 45]);
fis = addmf(fis, 'input', 1, 'quente', 'trapmf', [35 40 55 69.63]);

fis = addmf(fis, 'input', 2, 'fraco', 'trapmf', [-1.75 -1 -0.7 0]);
fis = addmf(fis, 'input', 2, 'ok', 'trimf', [-0.4 0 0.4]);
fis = addmf(fis, 'input', 2, 'forte', 'trapmf', [0 0.7 1.5 1.75]);

fis = addmf(fis, 'output', 1, 'fecha-rapido', 'trimf', [-1 -0.6 -0.3]);
fis = addmf(fis, 'output', 1, 'fecha-devagar', 'trimf', [-0.6 -0.3 0]);
fis = addmf(fis, 'output', 1, 'nada', 'trimf', [-0.3 0 0.3]);
fis = addmf(fis, 'output', 1, 'abre-devagar', 'trimf', [-0.3 0 0.3]);
fis = addmf(fis, 'output', 1, 'abre-rapido', 'trimf', [0.3 0.6 1]);

fis = addmf(fis, 'output', 2, 'fecha-devagar', 'trimf', [-1 -0.6 -0.3]);
fis = addmf(fis, 'output', 2, 'fecha-rapido', 'trimf', [-0.6 -0.3 0]);
fis = addmf(fis, 'output', 2, 'nada', 'trimf', [-0.3 0 0.3]);
fis = addmf(fis, 'output', 2, 'abre-devagar', 'trimf', [-0.3 0 0.3]);
fis = addmf(fis, 'output', 2, 'abre-rapido', 'trimf', [0.3 0.6 1]);

% 1. Se temperatura estiver fria e o fluxo fraco, então abre a torneira fria devagar e abre a torneira quente depressa.
% 2. Se temperatura estiver fria e o fluxo ok, então fecha a torneira  fria devagar e abre a torneira quente devagar.
% 3. Se temperatura estiver fria e o fluxo forte, então fecha a torneira fria depressa e fecha a torneira quente devagar.
% 4. Se temperatura estiver boa e o fluxo fraco, então abre a torneira fria devagar e abre a torneira quente devagar.
% 5. Se temperatura estiver boa e o fluxo ok, então não altera nenhuma das torneiras.
% 6. Se temperatura estiver boa e o fluxo forte, então fecha a torneira fria devagar e fecha a torneira quente devagar.
% 7. Se temperatura estiver quente e o fluxo fraco, então abre a torneira fria depressa e abre a torneira quente devagar.
% 8. Se temperatura estiver quente e o fluxo ok, então abre a torneira fria devagar e fecha a torneira quente devagar.
% 9. Se temperatura estiver boa e o fluxo forte, então fecha a torneira fria devagar fecha a torneira quente depressa.

regras = [1 1 4 5 1 1;
          1 2 2 4 1 1;
          1 3 1 2 1 1;
          2 1 4 4 1 1;
          2 2 3 3 1 1;
          2 3 2 2 1 1;
          3 1 5 4 1 1;
          3 2 4 2 1 1;
          3 3 2 1 1 1];
    
fis = addrule(fis, regras);
entrada = [1 1];
out = evalfis(entrada, fis);
fprintf('temperatura = %f\nfluxo = %f\nt-fria = %f\nt-quente = %f', entrada(1), entrada(2), out(1), out(2));
 
end