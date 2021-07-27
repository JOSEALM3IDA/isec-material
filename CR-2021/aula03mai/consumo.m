function out = consumo()

consumo_fis=newfis('consumo_fis');
consumo_fis = addvar(consumo_fis, 'input', 'aceleracao', [0 7000]);
consumo_fis = addvar(consumo_fis, 'input', 'terreno', [-30 30]);
consumo_fis = addvar(consumo_fis, 'input', 'pneus', [1 10]);
consumo_fis = addvar(consumo_fis, 'output', 'consumo', [0 10]);

consumo_fis = addmf(consumo_fis, 'input', 1, 'baixa', 'trimf', [-3800 0 3800]);
consumo_fis = addmf(consumo_fis, 'input', 1, 'media', 'trapmf', [2000 3800 5200 7000]);
consumo_fis = addmf(consumo_fis, 'input', 1, 'alta', 'trimf', [5200 8000 10800]);

consumo_fis = addmf(consumo_fis, 'input', 2, 'descida', 'trimf', [-60 -30 -6]);
consumo_fis = addmf(consumo_fis, 'input', 2, 'plano', 'trimf', [-20 0 20]);
consumo_fis = addmf(consumo_fis, 'input', 2, 'subida', 'trimf', [5 30 54]);

consumo_fis = addmf(consumo_fis, 'input', 3, 'velhos', 'pimf',  [-1 1 1.6 4]);
consumo_fis = addmf(consumo_fis, 'input', 3, 'usados', 'pimf',  [3 5 6 8]);
consumo_fis = addmf(consumo_fis, 'input', 3, 'novos', 'pimf',  [7 9 10 15]);



consumo_fis = addmf(consumo_fis, 'output', 1, 'baixo', 'trapmf',  [-3.6 -0.4 3 4]);
consumo_fis = addmf(consumo_fis, 'output', 1, 'medio', 'trapmf',  [3 4 6 7]);
consumo_fis = addmf(consumo_fis, 'output', 1, 'alto', 'trimf',  [6 8 10 13]);

%SE acelera??o baixa ou terreno plano ou pneus novos ENTAO consumo baixo
%SE acelera??o baixa e terreno plano e pneus novos ENTAO consumo baixo
%SE acelera??o baixa e pneus novo ENTAO consumo baixo
%SE acelera??o baixa e terreno plano e pneus novos ENTAO consumo baixo

%SE acelaracao baixa e terreno subida ENTAO consumo m?dio
%SE acelaracao media e terreno subida ENTAO consumo m?dio
%SE acelaracao m?dia e terreno descida ENTAO consumo m?dio
%SE acelera??o baixa e pneus velhos ENTAO consumo medio
%SE acelera??o m?dia e pneus usados ENTAO consumo medio

%SE acelaracao alta  ENTAO consumo alto
%SE acelaracao alta ou terreno subida ENTAO consumo alto
%SE aceleracao alta E terreno subida e pneus velhos entao consumo alto
%SE pneus velhos e terreno subida ENTAO consumo alto


regras=[1 1 1 1 1 2;
        1 2 3 1 1 1;
        1 0 3 1 1 1;
        1 2 3 1 1 1;
        1 3 1 1 1 1;
        1 3 0 2 1 1;
        2 1 0 2 1 1;
        2 1 0 2 1 1;
        1 0 1 2 1 1;
        1 0 2 2 1 1;
        3 0 0 3 1 1;
        3 3 0 3 1 2;
        3 3 1 3 1 1;
        0 3 1 3 1 1];
consumo_fis=addrule(consumo_fis, regras);

%acelera??o; terreno; pneus
entrada=[7000 30 1];
out = evalfis(entrada, consumo_fis)