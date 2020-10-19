function varargout = maquinaMNSED(varargin)
% MAQUINAMNSED MATLAB code for maquinaMNSED.fig
%      MAQUINAMNSED, by itself, creates a new MAQUINAMNSED or raises the existing
%      singleton*.
%
%      H = MAQUINAMNSED returns the handle to a new MAQUINAMNSED or the handle to
%      the existing singleton*.
%
%      MAQUINAMNSED('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MAQUINAMNSED.M with the given input arguments.
%
%      MAQUINAMNSED('Property','Value',...) creates a new MAQUINAMNSED or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before maquinaMNSED_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to maquinaMNSED_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help maquinaMNSED

% Last Modified by GUIDE v2.5 24-May-2020 16:23:18

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @maquinaMNSED_OpeningFcn, ...
                   'gui_OutputFcn',  @maquinaMNSED_OutputFcn, ...
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


% --- Executes just before maquinaMNSED is made visible.
function maquinaMNSED_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to maquinaMNSED (see VARARGIN)

% Choose default command line output for maquinaMNSED
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes maquinaMNSED wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = maquinaMNSED_OutputFcn(hObject, eventdata, handles) 
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
Atualizar(handles);

% --- Executes on button press in pbLimpar.
function pbLimpar_Callback(hObject, eventdata, handles)
% hObject    handle to pbLimpar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.eFuncaoF,'String','');                                          % Coloca o edit text 'eFuncaoF' vazio
set(handles.eFuncaoG,'String','');                                          % Coloca o edit text 'eFuncaoG' vazio
set(handles.eA,'String','');                                                % Coloca o edit text 'eA' vazio
set(handles.eB,'String','');                                                % Coloca o edit text 'eB' vazio
set(handles.eU0,'String','');                                               % Coloca o edit text 'eU0' vazio
set(handles.eV0,'String','');                                               % Coloca o edit text 'eV0' vazio
set(handles.eN,'String','');                                                % Coloca o edit text 'eN' vazio

axes(handles.axesGrafico);                                                  % Faz com que o sistema de eixos ativo seja o 'axesGrafico'
cla reset;                                                                  % Limpa os valores do grafico
set(handles.uiTabela, 'Data', {});                                          % Limpa os valores da tabela
set(handles.uiTabela,'ColumnName',{});                                      % Limpa os nomes da tabela

grelha = get(handles.cbGrelha, 'Value');
if grelha
    grid on;
else
    grid off;
end


% --- Executes on button press in cbGrelha.
function cbGrelha_Callback(hObject, eventdata, handles)
% hObject    handle to cbGrelha (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbGrelha
grelha = get(handles.cbGrelha, 'Value');
if grelha
    grid on;
else
    grid off;
end


% --- Executes on button press in cbSExacta.
function cbSExacta_Callback(hObject, eventdata, handles)
% hObject    handle to cbSExacta (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbSExacta


% --- Executes on button press in cbEuler.
function cbEuler_Callback(hObject, eventdata, handles)
% hObject    handle to cbEuler (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbEuler


% --- Executes on button press in cbHeun.
function cbHeun_Callback(hObject, eventdata, handles)
% hObject    handle to cbHeun (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbHeun


% --- Executes on button press in cbRK2.
function cbRK2_Callback(hObject, eventdata, handles)
% hObject    handle to cbRK2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbRK2


% --- Executes on button press in cbRK4.
function cbRK4_Callback(hObject, eventdata, handles)
% hObject    handle to cbRK4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbRK4


function eFuncaoG_Callback(hObject, eventdata, handles)
% hObject    handle to eFuncaoG (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eFuncaoG as text
%        str2double(get(hObject,'String')) returns contents of eFuncaoG as a double


% --- Executes during object creation, after setting all properties.
function eFuncaoG_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eFuncaoG (see GCBO)
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


function eFuncaoF_Callback(hObject, eventdata, handles)
% hObject    handle to eFuncaoF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eFuncaoF as text
%        str2double(get(hObject,'String')) returns contents of eFuncaoF as a double


% --- Executes during object creation, after setting all properties.
function eFuncaoF_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eFuncaoF (see GCBO)
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



function eU0_Callback(hObject, eventdata, handles)
% hObject    handle to eU0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eU0 as text
%        str2double(get(hObject,'String')) returns contents of eU0 as a double


% --- Executes during object creation, after setting all properties.
function eU0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eU0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eV0_Callback(hObject, eventdata, handles)
% hObject    handle to eV0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eV0 as text
%        str2double(get(hObject,'String')) returns contents of eV0 as a double


% --- Executes during object creation, after setting all properties.
function eV0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eV0 (see GCBO)
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


% --- Executes on button press in pbExportar.
function pbExportar_Callback(hObject, eventdata, handles)
% hObject    handle to pbExportar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
filename = 'maquinaMSED.xlsx';
if exist(filename, 'file')                                                  % Se o ficheiro já existir apaga-o
    delete(filename);                                                       % Apaga o ficheiro
end

% Criação de uma tabela com os cabeçalhos e os dados correspondentes e gravação num ficheiro excel
header=get(handles.uiTabela,'ColumnName')';                                 % Header recebe os nomes do cabeçalho
data=get(handles.uiTabela,'Data');                                          % Data recebe os valores dos resultados
tabela=[header;data];                                                       % Criação de uma tabela com os cabeçalhos e respetivos resultados
xlswrite(filename,tabela,'Sheet1','B2');                                    % Grava a tabela no ficheiro excell
winopen(filename);                                                          % Abre o ficheiro excell



function Atualizar(handles)

axes(handles.axesGrafico);                                                  % Faz com que o sistema de eixos ativo seja o 'axesGrafico'
cla reset;                                                                  % Limpa os valores do grafico
set(handles.uiTabela, 'Data', {});                                          % Limpa os valores da tabela
set(handles.uiTabela,'ColumnName',{});                                      % Limpa os nomes da tabela

strF = get(handles.eFuncaoF,'String');                                      % Obtem a string existente no edit text 'eF' e coloca em strF
f=@(t,u,v) eval(vectorize(strF));                                          
strG = get(handles.eFuncaoG,'String');                                      % Obtem a string existente no edit text 'eF' e coloca em strF
g=@(t,u,v) eval(vectorize(strG));                                          


a   = str2num(get(handles.eA,'String'));                                    % Obtem a string existente no edit text 'eA', converte para numero e coloca em a
b   = str2num(get(handles.eB,'String'));                                    % Obtem a string existente no edit text 'eB', converte para numero e coloca em b
n   = str2num(get(handles.eN,'String'));                                    % Obtem a string existente no edit text 'eN', converte para numero e coloca em n
u0  = str2num(get(handles.eU0,'String'));                                   % Obtem a string existente no edit text 'eu0', converte para numero e coloca em u0
v0  = str2num(get(handles.eV0,'String'));                                   % Obtem a string existente no edit text 'ev0', converte para numero e coloca em v0


% Verifica no Button Group qual foi a escolha do utilizador e guarda o valor em 'escolha'
escolhabg=get(handles.bgMetodos,'SelectedObject');
escolha=find([handles.rbEuler,...
              handles.rbHeun,...
              handles.rbRK2,...
              handles.rbRK4,...
              handles.rbTodos]==escolhabg);
          
EULER=1;                    % EULER recebe o valor de 1
HEUN=2;                     % HEUN recebe o valor de 2
RK2=3;                      % RK2 recebe o valor de 3
RK4=4;                      % RK4 recebe o valor de 4
TODOS=5;                    % TODOS recebe o valor de 5
    
% Criacao das Excepcoes (Mensagens de erro)
testeFunc=MException('MATLAB:MyAtualizar:badFunc',....
                     'Introduza uma funcao em t, u e v');
testeA=MException('MATLAB:Atualizar:badNReal',....
                     'Valor de "a" nao introduzido ou nao real');
testeB=MException('MATLAB:Atualizar:badNReal',....
                     'Valor de "b" nao introduzido ou nao real');
testeBA=MException('MATLAB:Atualizar:badNReal',....
                     'Valor de "b" tem de ser superior a "a"');
testeN=MException('MATLAB:Atualizar:badNReal',....
                     'Introduza "n" inteiro e maior que zero!');
testeU0=MException('MATLAB:Atualizar:badNReal',....
                     'Valor inicial "u0" nao introduzido ou nao real');
testeV0=MException('MATLAB:Atualizar:badNReal',....
                     'Valor inicial "v0" nao introduzido ou nao real');
               
                 
% validacoes
try % o try serve para apanhar possiveis erros no input do user
    fTeste=f(sym('t'),sym('u'),sym('v'));
    gTeste=g(sym('t'),sym('u'),sym('v'));
catch Armenio
    throw(testeFunc); % Caso a verificacao falhe chama a Excepcao 'testeFunc'
end

if ~(isscalar(a) && isreal(a)), throw(testeA); end                          % Se 'a' nao for um numero e se nao for um numero real chama a Excepcao 'testeA'
if ~(isscalar(b) && isreal(b)), throw(testeB); end                          % Se 'b' nao for um numero e se nao for um numero real chama a Excepcao 'testeB'
if (a>b), throw(testeBA); end                                               % Se 'a' for maior que 'b' chama a Excepcao 'testeBA'
if ~(isscalar(n) && (mod(n,1) == 0) && n > 0), throw(testeN); end           % Se 'n' nao for um numero e se nao for um numero par chama a Excepcao 'testeA'
if ~(isscalar(u0) && isreal(u0)), throw(testeU0); end                       % Se 'u0' nao for um numero e se nao for um numero real chama a Excepcao 'testeU0'
if ~(isscalar(v0) && isreal(v0)), throw(testeV0); end                       % Se 'v0' nao for um numero e se nao for um numero real chama a Excepcao 'testeV0'

t = a:(b-a)/n:b;

% Switch case dos metodos a aplicar segundo as escolhas dos utilizadores
todos = 0;
switch escolha
    case EULER                                                              % Caso a escolha do utilizador tenha sido o metodo de Euler
        [~,u,~]=N_EulerSED(f,g,a,b,n,u0,v0);
    case HEUN                                                               % Caso a escolha do utilizador tenha sido o metodo de Euler
        [~,u,~]=N_HeunSED(f,g,a,b,n,u0,v0);
    case RK2                                                                % Caso a escolha do utilizador tenha sido o metodo de Euler
        [~,u,~]=N_RK2SED(f,g,a,b,n,u0,v0);
    case RK4                                                                % Caso a escolha do utilizador tenha sido o metodo de Euler
        [~,u,~]=N_RK4SED(f,g,a,b,n,u0,v0);
    case TODOS
        todos = 1;
end

[uSolucao,vSolucao] = sExataSED(strF,strG,a,u0,v0);                         % Calculo da Solucao exata

if (uSolucao == 0 && vSolucao == 0)
    linear = 0;
else
    linear = 1;
end

if (linear && ~todos) % Se nao estiver selecionada a opcao "todos" e as ED forem lineares
    hold on
    
    uExata = uSolucao(t);
    uExata = double(uExata);
    
    plot(t,uExata,'-*b');
    plot(t, u, 'r');
    
    erro = u - uExata;
    
    tabela=[t.', uExata.', u.', erro.'];
    set(handles.uiTabela,'Data',num2cell(tabela));                          % Coloca os dados na tabela 'uiTabela'
    set(handles.uiTabela,'ColumnName',...                                   % Coloca os titulos das colunas na tabela 'uiTabela'
     [{'t'},{'Exata'},{'Aproximada'},{'Erro'}]);
    legend('Exata','Aproximada');
    
    hold off
elseif (~linear && todos) % Se estiver selecionada a opcao "todos" e as ED não forem lineares
    hold on
    
    [~,uEuler,~]=N_EulerSED(f,g,a,b,n,u0,v0);
    [~,uHeun,~]=N_HeunSED(f,g,a,b,n,u0,v0);
    [~,uRK2,~]=N_RK2SED(f,g,a,b,n,u0,v0);
    [~,uRK4,~]=N_RK4SED(f,g,a,b,n,u0,v0);
    
    plot(t, uEuler, 'r');
    plot(t, uHeun, 'm');
    plot(t, uRK2, 'g');
    plot(t, uRK4, 'k');
    
    tabela=[t.', uEuler.', uHeun.', uRK2.', uRK4.'];
    set(handles.uiTabela,'Data',num2cell(tabela));                          % Coloca os dados na tabela 'uiTabela'
    set(handles.uiTabela,'ColumnName',...                                   % Coloca os titulos das colunas na tabela 'uiTabela'
     [{'t'},{'EULER'},{'HEUN'},{'RK2'},{'RK4'}]);
    legend('EULER', 'HEUN', 'RK2', 'RK4');
    
    hold off
elseif (linear && todos) % Se estiver selecionada a opcao "todos" e as ED forem lineares
    hold on
        
    uExata = uSolucao(t);
    uExata = double(uExata);
    plot(t,uExata,'-*b');
    
    [~,uEuler,~]=N_EulerSED(f,g,a,b,n,u0,v0);
    [~,uHeun,~]=N_HeunSED(f,g,a,b,n,u0,v0);
    [~,uRK2,~]=N_RK2SED(f,g,a,b,n,u0,v0);
    [~,uRK4,~]=N_RK4SED(f,g,a,b,n,u0,v0);
    
    plot(t, uEuler, 'r');
    plot(t, uHeun, 'm');
    plot(t, uRK2, 'g');
    plot(t, uRK4, 'k');
    
    erroEuler = uEuler - uExata;
    erroHeun = uHeun - uExata;
    erroRK2 = uRK2 - uExata;
    erroRK4 = uRK4 - uExata;
    
    tabela=[t.', uExata.' , uEuler.', erroEuler.', uHeun.', erroHeun.', uRK2.', erroRK2.', uRK4.', erroRK4.'];
    set(handles.uiTabela,'Data',num2cell(tabela));                          % Coloca os dados na tabela 'uiTabela'
    set(handles.uiTabela,'ColumnName',...                                   % Coloca os titulos das colunas na tabela 'uiTabela'
     [{'t'},{'Exata'},{'EULER'},{'ERRO EULER'},{'HEUN'},{'ERRO HEUN'},{'RK2'},{'ERRO RK2'},{'RK4'},{'ERRO RK4'}]);
    legend('Exata', 'EULER', 'HEUN', 'RK2', 'RK4');
    
    hold off
elseif ~todos && ~linear % Se nao estiver selecionada a opcao "todos" e as nao ED forem lineares
    plot(t, u, 'r');
    
    tabela=[t.', u.'];
    set(handles.uiTabela,'Data',num2cell(tabela));                          % Coloca os dados na tabela 'uiTabela'
    set(handles.uiTabela,'ColumnName',...                                   % Coloca os titulos das colunas na tabela 'uiTabela'
     [{'t'},{'Solução Aproximada'}]);
    legend('Solução Aproximada');
else
end

grelha = get(handles.cbGrelha, 'Value');
if grelha
    grid on;
else
    grid off;
end
 
% --------------------------------------------------------------------
function MFicheiro_Callback(hObject, eventdata, handles)
% hObject    handle to MFicheiro (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function MProblemas_Callback(hObject, eventdata, handles)
% hObject    handle to MProblemas (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% --------------------------------------------------------------------
function MPendulo_Callback(hObject, eventdata, handles)
% hObject    handle to MPendulo (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Valores de cada campo especificos do exemplo PENDULO
set(handles.eFuncaoF,'String','v');                                         % Coloca o edit text 'eFuncaoF'
set(handles.eFuncaoG,'String','-sin(u)-0.3*v');                             % Coloca o edit text 'eFuncaoG'
set(handles.eA,'String','0');                                               % Coloca o edit text 'eA'
set(handles.eB,'String','15');                                              % Coloca o edit text 'eB'
set(handles.eU0,'String','pi/2');                                           % Coloca o edit text 'eU0'
set(handles.eV0,'String','0');                                              % Coloca o edit text 'eV0'
set(handles.eN,'String','100');                                             % Coloca o edit text 'eN'

Atualizar(handles);



% --------------------------------------------------------------------
function MLivreAmortecido_Callback(hObject, eventdata, handles)
% hObject    handle to MLivreAmortecido (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Valores de cada campo especificos do exemplo MOVIMENTO LIVRE AMORTECIDO
set(handles.eFuncaoF,'String','v');                                         % Coloca o edit text 'eFuncaoF'
set(handles.eFuncaoG,'String','-10*v-25*u');                                % Coloca o edit text 'eFuncaoG'
set(handles.eA,'String','0');                                               % Coloca o edit text 'eA'
set(handles.eB,'String','2');                                               % Coloca o edit text 'eB'
set(handles.eU0,'String','0');                                              % Coloca o edit text 'eU0'
set(handles.eV0,'String','-4');                                             % Coloca o edit text 'eV0'
set(handles.eN,'String','100');                                             % Coloca o edit text 'eN'

Atualizar(handles);



% --------------------------------------------------------------------
function MVibMec_Callback(hObject, eventdata, handles)
% hObject    handle to MVibMec (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Valores de cada campo especificos do exemplo MODELO VIBRATORIO MECANICO
set(handles.eFuncaoF,'String','v');                                         % Coloca o edit text 'eFuncaoF'
set(handles.eFuncaoG,'String','-2*v-2*u+4*cos(t)+2*sin(t)');                % Coloca o edit text 'eFuncaoG'
set(handles.eA,'String','0');                                               % Coloca o edit text 'eA'
set(handles.eB,'String','15');                                              % Coloca o edit text 'eB'
set(handles.eU0,'String','0');                                              % Coloca o edit text 'eU0'
set(handles.eV0,'String','3');                                              % Coloca o edit text 'eV0'
set(handles.eN,'String','100');                                             % Coloca o edit text 'eN'

Atualizar(handles);


% --------------------------------------------------------------------
function MMovHS_Callback(hObject, eventdata, handles)
% hObject    handle to MMovHS (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Valores de cada campo especificos do exemplo MOVIMENTO HARMONICO SIMPLES
set(handles.eFuncaoF,'String','v');                                         % Coloca o edit text 'eFuncaoF'
set(handles.eFuncaoG,'String','-16*u');                                     % Coloca o edit text 'eFuncaoG'
set(handles.eA,'String','0');                                               % Coloca o edit text 'eA'
set(handles.eB,'String','10');                                              % Coloca o edit text 'eB'
set(handles.eU0,'String','9');                                              % Coloca o edit text 'eU0'
set(handles.eV0,'String','0');                                              % Coloca o edit text 'eV0'
set(handles.eN,'String','100');                                             % Coloca o edit text 'eN'

Atualizar(handles);

% --------------------------------------------------------------------
function CEleSer_Callback(hObject, eventdata, handles)
% hObject    handle to CEleSer (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Valores de cada campo especificos do exemplo CIRCUITOS ELÉTRICOS EM SÉRIE
set(handles.eFuncaoF,'String','v');                                         % Coloca o edit text 'eFuncaoF'
set(handles.eFuncaoG,'String','-5*v-4*u+2*exp(-t/4)');                      % Coloca o edit text 'eFuncaoG'
set(handles.eA,'String','0');                                               % Coloca o edit text 'eA'
set(handles.eB,'String','10');                                              % Coloca o edit text 'eB'
set(handles.eU0,'String','0');                                              % Coloca o edit text 'eU0'
set(handles.eV0,'String','0');                                              % Coloca o edit text 'eV0'
set(handles.eN,'String','100');                                             % Coloca o edit text 'eN'

Atualizar(handles);


% --------------------------------------------------------------------
function MSobre_Callback(hObject, eventdata, handles)
% hObject    handle to MSobre (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function MAutores_Callback(hObject, eventdata, handles)
% hObject    handle to MAutores (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Autores();

% --------------------------------------------------------------------
function MSair_Callback(hObject, eventdata, handles)
% hObject    handle to MSair (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
SN = questdlg('Quer mesmo sair?','SAIR','Sim','Não','Sim');                 % Abre uma mensagem a perguntar ao utilizador 'Quer mesmo sair?'
if strcmp(SN,'Não')                                                         % Caso o utilizador escolha a opção não, então a figura mantém-se aberta
    return 
end
delete(hObject);                                                            % Se não, apaga a figura

% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
MSair_Callback(hObject, eventdata, handles);


% --------------------------------------------------------------------
function MRelatorio_Callback(hObject, eventdata, handles)
% hObject    handle to MRelatorio (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
winopen('Relatorio_Atividade02.pdf')                                        % Abre o ficheiro 'Relatoro_Atividade02.pdf'
