%MaquinaEDO1 - GUI onde mostra os graficos e tabelas de valores
% 
%   03/03/2020 - ArménioCorreia .: armenioc@isec.pt 
%   22/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   22/04/2020 - José Almeida .: a2019129077@isec.pt
%   22/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function varargout = MaquinaEDO1(varargin)
% MAQUINAEDO1 M-file for MaquinaEDO1.fig
%      MAQUINAEDO1, by itself, creates a new MAQUINAEDO1 or raises the existing
%      singleton*.
%
%      H = MAQUINAEDO1 returns the handle to a new MAQUINAEDO1 or the handle to
%      the existing singleton*.
%
%      MAQUINAEDO1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MAQUINAEDO1.M with the given input arguments.
%
%      MAQUINAEDO1('Property','Value',...) creates a new MAQUINAEDO1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before MaquinaEDO1_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to MaquinaEDO1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help MaquinaEDO1

% Last Modified by GUIDE v2.5 24-Apr-2020 15:16:54

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @MaquinaEDO1_OpeningFcn, ...
                   'gui_OutputFcn',  @MaquinaEDO1_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before MaquinaEDO1 is made visible.
function MaquinaEDO1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to MaquinaEDO1 (see VARARGIN)

% Choose default command line output for MaquinaEDO1
handles.output = hObject;
set(hObject,'Name','Equações Diferenciais Ordinárias');

% Update handles structure
guidata(hObject, handles);
MyAtualizar(handles);

% UIWAIT makes MaquinaEDO1 wait for user response (see UIRESUME)
% uiwait(handles.figureMaquinaEDO1);


% --- Outputs from this function are returned to the command line.
function varargout = MaquinaEDO1_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pbAtualizar.
function pbAtualizar_Callback(hObject, eventdata, handles)
% hObject    handle to pbAtualizar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
MyAtualizar(handles);                                                       % Chama a função 'MyAtualizar'


function eF_Callback(hObject, eventdata, handles)
% hObject    handle to eF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eF as text
%        str2double(get(hObject,'String')) returns contents of eF as a double


% --- Executes during object creation, after setting all properties.
function eF_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eA_Callback(hObject, eventdata, handles)
% hObject    handle to eA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eA as text
%        str2double(get(hObject,'String')) returns contents of eA as a double


% --- Executes during object creation, after setting all properties.
function eA_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eB_Callback(hObject, eventdata, handles)
% hObject    handle to eB (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eB as text
%        str2double(get(hObject,'String')) returns contents of eB as a double


% --- Executes during object creation, after setting all properties.
function eB_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eB (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eN_Callback(hObject, eventdata, handles)
% hObject    handle to eN (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eN as text
%        str2double(get(hObject,'String')) returns contents of eN as a double


% --- Executes during object creation, after setting all properties.
function eN_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eN (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eY0_Callback(hObject, eventdata, handles)
% hObject    handle to eY0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eY0 as text
%        str2double(get(hObject,'String')) returns contents of eY0 as a double


% --- Executes during object creation, after setting all properties.
function eY0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eY0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function MyAtualizar(handles)


strF= get(handles.eF,'String');                                             % Obtém a string existente no edit text 'eF' e coloca em strF
f   = @(t,y) eval(vectorize(strF));                                         % 

a   = str2num(get(handles.eA,'String'));                                    % Obtém a string existente no edit text 'eA', converte para numero e coloca em a
b   = str2num(get(handles.eB,'String'));                                    % Obtém a string existente no edit text 'eB', converte para numero e coloca em b
n   = str2num(get(handles.eN,'String'));                                    % Obtém a string existente no edit text 'eN', converte para numero e coloca em n
y0  = str2num(get(handles.eY0,'String'));                                   % Obtém a string existente no edit text 'eY0', converte para numero e coloca em y0

% Verifica no Button Group qual foi a escolha do utilizador e guarda o valor em 'escolha'
escolhabg=get(handles.bgMetodos,'SelectedObject');
escolha=find([handles.rbEuler,...
              handles.rbHeun,...
              handles.rbRK2,...
              handles.rbRK4,...
              handles.rbODE45,...
              handles.rbPontoMedio,...
              handles.rbTodos]==escolhabg);
EULER=1;                    % EULER recebe o valor de 1
HEUN=2;                     % HEUN recebe o valor de 2
RK2=3;                      % RK2 recebe o valor de 3
RK4=4;                      % RK4 recebe o valor de 4
ODE45=5;                    % ODE45 recebe o valor de 5
PM=6;                       % PM recebe o valor de 6
TODOS=7;                    % TODOS recebe o valor de 7
    
% Criação das Excepções (Mensagens de erro)
testeFunc=MException('MATLAB:MyAtualizar:badFunc',....
                     'Introduza uma função em t e y');
testeA=MException('MATLAB:MyAtualizar:badNReal',....
                     'Valor de "a" não introduzido ou não real');
testeB=MException('MATLAB:MyAtualizar:badNReal',....
                     'Valor de "b" não introduzido ou não real');
testeBA=MException('MATLAB:MyAtualizar:badNReal',....
                     'Valor de "b" tem de ser superior a "a"');
testeN=MException('MATLAB:MyAtualizar:badNReal',....
                     'Introduza "n" inteiro e maior que zero!');
testeY0=MException('MATLAB:MyAtualizar:badNReal',....
                     'Valor inicial "y0" não introduzido ou não real');

               
                 
try  
    % validações
    try                 % o try serve para apanhar possiveis erros no input do user
           fTeste=f(sym('t'),sym('y'));             % Verifica se a função é em 't' e/ou em 'y'
    catch
           throw(testeFunc);                        % Caso a verificação falhe chama a Excepção 'testeFunc'
    end 
    
    if ~(isscalar(a) && isreal(a)), throw(testeA); end                      % Se 'a' não for um número e se não for um numero real chama a Excepção 'testeA'
    if ~(isscalar(b) && isreal(b)), throw(testeB); end                      % Se 'b' não for um número e se não for um numero real chama a Excepção 'testeB'
    if (a>b), throw(testeBA); end                                           % Se 'a' for maior que 'b' chama a Excepção 'testeBA'
    if ~(isscalar(n) && (mod(n,1) == 0) && n > 0), throw(testeN); end       % Se 'n' não for um número e se não for um numero par chama a Excepção 'testeA'
    if ~(isscalar(y0) && isreal(y0)), throw(testeY0); end                   % Se 'y0' não for um número e se não for um numero real chama a Excepção 'testeY0'
    
    % Solução exacta
    sExata=dsolve(['Dy=',strF],...
          ['y(',num2str(a),')=',num2str(y0)]);
    t=a:(b-a)/n:b;
    yExata = eval(vectorize(char(sExata)));
    
    plot(t,yExata);                                                         % Criação do gráfico com os valores da solução exacta
    hold on                                                                 % Necessário colocar para podermos apresentar mais resultados no mesmo gráfico
    
    % Switch case que vai executar segundo as escolhas dos utilizadores
    switch escolha
        case EULER                                                          % Caso a escolha do utilizador tenha sido o método de Euler
            yEuler = N_Euler(f,a,b,n,y0);                                   % Chama a função N_Euler e coloca o resultado em 'yEuler'
            erroEuler=abs(yExata-yEuler);                                   % Calcula o erro de Euler e coloca em 'erroEuler'
            
            plot(t,yEuler,'r');                                             % Mostra no gráfico os valores de 'yEuler' a vermelho
            legend('yExata','yEuler');                                      % Coloca uma legenda no gráfico
            tabela=[t.',yExata.',yEuler.',erroEuler.'];                     % Cria uma tabela com os valores da Solução Exata, do Método de Euler e do erro de Euler
            set(handles.uiTabela,'Data',num2cell(tabela));                  % Coloca os dados na tabela 'uiTabela'
            set(handles.uiTabela,'ColumnName',...                           % Coloca os títulos das colunas na tabela 'uiTabela'
                 [{'t'},{'Exata'},{'Euler'},{'ErroEuler'}]);
        case HEUN                                                           % Caso a escolha do utilizador tenha sido o método de Heun
            yHeun = N_Heun(f,a,b,n,y0);                                     % Chama a função N_Heun e coloca o resultado em 'yHeun'
            erroHeun=abs(yExata-yHeun);                                     % Calcula o erro de Heun e coloca em 'erroHeun'
            
            plot(t,yHeun,'g');                                              % Mostra no gráfico os valores de 'yHeun' a verde
            legend('yExata','yHeun');                                       % Coloca uma legenda no gráfico
            tabela=[t.',yExata.',yHeun.',erroHeun.'];                       % Cria uma tabela com os valores da Solução Exata, do Método de Heun e do erro de Heun
            set(handles.uiTabela,'Data',num2cell(tabela));                  % Coloca os dados na tabela 'uiTabela'
            set(handles.uiTabela,'ColumnName',...                           % Coloca os títulos das colunas na tabela 'uiTabela'
                  [{'t'},{'Exata'},{'Heun'},{'ErroHeun'}]);                 
        case RK2                                                            % Caso a escolha do utilizador tenha sido o método RK2
            yRK2 = N_RK2(f,a,b,n,y0);                                       % Chama a função N_RK2 e coloca o resultado em 'yRK2'
            erroRK2=abs(yExata-yRK2);                                       % Calcula o erro de RK2 e coloca em 'errpRK2'
            
            plot(t,yRK2,'b');                                               % Mostra no gráfico os valores de 'yRK2' a blue
            legend('yExata','yRK2');                                        % Coloca uma legenda no gráfico
            tabela=[t.',yExata.',yRK2.',erroRK2.'];                         % Cria uma tabela com os valores da Solução Exata, do Método RK2 e do erro de RK2
            set(handles.uiTabela,'Data',num2cell(tabela));                  % Coloca os dados na tabela 'uiTabela'
            set(handles.uiTabela,'ColumnName',...                           % Coloca os títulos das colunas na tabela 'uiTabela'
                  [{'t'},{'Exata'},{'RK2'},{'ErroRK2'}]);                   
        case RK4                                                            % Caso a escolha do utilizador tenha sido o método RK4
            yRK4 = N_RK4(f,a,b,n,y0);                                       % Chama a função N_RK4 e coloca o resultado em 'yRK4'
            erroRK4=abs(yExata-yRK4);                                       % Calcula o erro de RK4 e coloca em 'erroRK4'
            
            plot(t,yRK4,'k');                                               % Mostra no gráfico os valores de 'yRK4' a preto
            legend('yExata','yRK4');                                        % Coloca uma legenda no gráfico
            tabela=[t.',yExata.',yRK4.',erroRK4.'];                         % Cria uma tabela com os valores da Solução Exata, do Método RK4 e do erro de RK4
            set(handles.uiTabela,'Data',num2cell(tabela));                  % Coloca os dados na tabela 'uiTabela'
            set(handles.uiTabela,'ColumnName',...                           % Coloca os títulos das colunas na tabela 'uiTabela'
                 [{'t'},{'Exata'},{'RK4'},{'ErroRK4'}]);
        case ODE45                                                          % Caso a escolha do utilizador tenha sido a utilização da função ODE45
            yODE45 = N_ODE45(f,a,b,n,y0);                                   % Chama a função N_ODE45 e coloca o resultado em 'yODE45'
            erroODE45=abs(yExata-yODE45);                                   % Calcula o erro de ODE45 e coloca em 'erroODE45'
            
            plot(t,yODE45,'m');                                             % Mostra no gráfico os valores de 'yODE45' a magenta
            legend('yExata','yODE45');                                      % Coloca uma legenda no gráfico
            tabela=[t.',yExata.',yODE45.',erroODE45.'];                     % Cria uma tabela com os valores da Solução Exata, da função ODE45 e do erro de ODE45
            set(handles.uiTabela,'Data',num2cell(tabela));                  % Coloca os dados na tabela 'uiTabela'
            set(handles.uiTabela,'ColumnName',...                           % Coloca os títulos das colunas na tabela 'uiTabela'
                 [{'t'},{'Exata'},{'ODE45'},{'ErroODE45'}]);
        case PM                                                             % Caso a escolha do utilizador tenha sido o método do Ponto Médio
            yPM = N_PM(f,a,b,n,y0);                                         % Chama a função N_PM e coloca o resultado em 'yPM'
            erroPM=abs(yExata-yPM);                                         % Calcula o erro de PM e coloca em 'erroPM'
            
            plot(t,yPM,'c');                                                % Mostra no gráfico os valores de 'yPM' a cyan
            legend('yExata','yPontoMedio');                                 % Coloca uma legenda no gráfico
            tabela=[t.',yExata.',yPM.',erroPM.'];                           % Cria uma tabela com os valores da Solução Exata, do Método do Ponto Médio e do erro do Ponto Médio
            set(handles.uiTabela,'Data',num2cell(tabela));                  % Coloca os dados na tabela 'uiTabela'
            set(handles.uiTabela,'ColumnName',...                           % Coloca os títulos das colunas na tabela 'uiTabela'
                 [{'t'},{'Exata'},{'PontoMedio'},{'ErroPontoMedio'}]);
        case TODOS                                                          
            
            yEuler = N_Euler(f,a,b,n,y0);                                   % Chama a função N_Euler e coloca o resultado em 'yEuler'
            erroEuler=abs(yExata-yEuler);                                   % Calcula o erro de Euler e coloca em 'erroEuler'
            plot(t,yEuler,'r');                                             % Mostra no gráfico os valores de 'yEuler' a vermelho
            
            yHeun = N_Heun(f,a,b,n,y0);                                     % Chama a função N_Heun e coloca o resultado em 'yHeun'
            erroHeun=abs(yExata-yHeun);                                     % Calcula o erro de Heun e coloca em 'erroHeun'
            plot(t,yHeun,'g');                                              % Mostra no gráfico os valores de 'yHeun' a verde

            yRK2 = N_RK2(f,a,b,n,y0);                                       % Chama a função N_RK2 e coloca o resultado em 'yRK2'
            erroRK2=abs(yExata-yRK2);                                       % Calcula o erro de RK2 e coloca em 'errpRK2'
            plot(t,yRK2,'b');                                               % Mostra no gráfico os valores de 'yRK2' a blue
            
            yRK4 = N_RK4(f,a,b,n,y0);                                       % Chama a função N_RK4 e coloca o resultado em 'yRK4'
            erroRK4=abs(yExata-yRK4);                                       % Calcula o erro de RK4 e coloca em 'erroRK4'
            plot(t,yRK4,'k');                                               % Mostra no gráfico os valores de 'yRK4' a preto
            
            yODE45 = N_ODE45(f,a,b,n,y0);                                   % Chama a função N_ODE45 e coloca o resultado em 'yODE45'
            erroODE45=abs(yExata-yODE45);                                   % Calcula o erro de ODE45 e coloca em 'erroODE45'
            plot(t,yODE45,'m');                                             % Mostra no gráfico os valores de 'yODE45' a magenta
            
            yPM = N_PM(f,a,b,n,y0);                                         % Chama a função N_PM e coloca o resultado em 'yPM'
            erroPM=abs(yExata-yPM);                                         % Calcula o erro de PM e coloca em 'erroPM'
            plot(t,yPM,'c');                                                % Mostra no gráfico os valores de 'yPM' a cyan
 
            legend('yExata','yEuler','yHeun','yRK2','yRK4','yODE45','yPM'); % Coloca uma legenda no gráfico
  
            tabela=[t.',yExata.',yEuler.',erroEuler.',yHeun.',erroHeun.',yRK2.',erroRK2.',...   % Cria uma tabela com todos os valores da Solução Exacta, dos métodos e respetivos erros
                     yRK4.',erroRK4.',yODE45.',erroODE45.',yPM.',erroPM.'];  
            set(handles.uiTabela,'Data',num2cell(tabela));                                      % Coloca os dados na tabela 'uiTabela'
            set(handles.uiTabela,'ColumnName',...                                               % Coloca os títulos das colunas na tabela 'uiTabela'
                 [{'t'},{'Exata'},{'Euler'},{'erroEuler'},{'Heun'},{'erroHeun'},{'RK2'},...
                 {'erroRK2'},{'RK4'},{'erroRK4'},{'ODE45'},{'erroODE45'},{'PontoMedio'},{'erroPM'}]);
    end
    hold off                                                                % Coloca-se quando não se quer inserir mais valores no mesmo gráfico
    grid on                                                                 % Mostra a grelha no gráfico
catch Me
    errordlg(Me.message,'ERRO','modal')
end


% --------------------------------------------------------------------
function MFile_Callback(hObject, eventdata, handles)
% hObject    handle to MFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function MSair_Callback(hObject, eventdata, handles)
% hObject    handle to MSair (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
SN = questdlg('Quer mesmo sair?','SAIR','Sim','Não','Sim');                 % abre uma mensagem a perguntar ao utilizador 'Quer mesmo sair?'
if strcmp(SN,'Não')                                                         % caso o utilizador escolha a opção não, então a figura 'Autores' mantém-se aberta
    return
end
delete(handles.figureMaquinaEDO1);                                          % senão, apaga a figura

% --- Executes when user attempts to close figureMaquinaEDO1.
function figureMaquinaEDO1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figureMaquinaEDO1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
%delete(hObject);
MSair_Callback([], [], handles);                                             % Chama a função 'MSair'


% --- Executes on button press in pbLimparDados.
function pbLimparDados_Callback(hObject, eventdata, handles)
% hObject    handle to pbLimparDados (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.eF,'String','');                                                % Coloca o edit text 'eF' vazio
set(handles.eA,'String','');                                                % Coloca o edit text 'eA' vazio
set(handles.eB,'String','');                                                % Coloca o edit text 'eB' vazio
set(handles.eN,'String','');                                                % Coloca o edit text 'eN' vazio
set(handles.eY0,'String','');                                               % Coloca o edit text 'eY0' vazio
axes(handles.axes1);                                                        % Faz com que o sistema de eixos ativo seja o 'axes1'
cla reset;                                                                  % Limpa os valores do gráfico
set(handles.uiTabela, 'Data', {});                                          % Limpa os valores da tabela
set(handles.uiTabela,'ColumnName',{});                                      % Limpa os nomes da tabela


% --- Executes on button press in pbVoltar.
function pbVoltar_Callback(hObject, eventdata, handles)
% hObject    handle to pbVoltar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
figHandles = findobj('type', 'figure');
delete(figHandles);                                                         % Apaga a figura
Atividade01_MNEDO();                                                        % Abre o ficheiro 'Atividade01_MNEDO'


% --- Executes on button press in pbExcel.
function pbExcel_Callback(hObject, eventdata, handles)
% hObject    handle to pbExcel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
filename = 'MetodosNumericosMaquina.xlsx';                                  % Abre o ficheiro pdf e associa a 'filename'
if exist(filename, 'file')                                                  % Se o ficheiro já existir apaga-o
    delete(filename);                                                       % Apaga o ficheiro
end

%criação de uma tabela com os cabeçalhos e os dados correspondentes e gravação num ficheiro excell
header=get(handles.uiTabela,'ColumnName')';     % header recebe os nomes do cabeçalho
data=get(handles.uiTabela,'Data');              % data recebe os valores dos resultados
tabela=[header;data];                           % criação de uma tabela com os cabeçalhos e respetivos resultados
xlswrite(filename,tabela,'Sheet1','B2');        % grava a tabela no ficheiro excell
winopen(filename);                              % abre o ficheiro excell
