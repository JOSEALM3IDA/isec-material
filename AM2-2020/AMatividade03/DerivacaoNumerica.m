% DerivacaoNumerica Derivação Numérica
% Máquina para calcular soluções aproximadas de derivadas
% --- 12/01/2016  Arménio Correia   armenioc@isec.pt
function varargout = DerivacaoNumerica(varargin)
% DERIVACAONUMERICA M-file for DerivacaoNumerica.fig
%      DERIVACAONUMERICA, by itself, creates a new DERIVACAONUMERICA or raises the existing
%      singleton*.
%
%      H = DERIVACAONUMERICA returns the handle to a new DERIVACAONUMERICA or the handle to
%      the existing singleton*.
%
%      DERIVACAONUMERICA('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in DERIVACAONUMERICA.M with the given input arguments.
%
%      DERIVACAONUMERICA('Property','Value',...) creates a new DERIVACAONUMERICA or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before DerivacaoNumerica_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to DerivacaoNumerica_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help DerivacaoNumerica

% Last Modified by GUIDE v2.5 06-Jun-2020 23:20:59

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @DerivacaoNumerica_OpeningFcn, ...
                   'gui_OutputFcn',  @DerivacaoNumerica_OutputFcn, ...
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


% --- Executes just before DerivacaoNumerica is made visible.
function DerivacaoNumerica_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to DerivacaoNumerica (see VARARGIN)

% Choose default command line output for DerivacaoNumerica
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes DerivacaoNumerica wait for user response (see UIRESUME)
% uiwait(handles.figureDerivacaoNumerica);
pbLimpar_Callback(hObject, eventdata, handles)


% --- Outputs from this function are returned to the command line.
function varargout = DerivacaoNumerica_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pbAtualiza.
function pbAtualiza_Callback(hObject, eventdata, handles)
% hObject    handle to pbAtualiza (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
MyAtualizar(handles);


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



function eH_Callback(hObject, eventdata, handles)
% hObject    handle to eH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eH as text
%        str2double(get(hObject,'String')) returns contents of eH as a double


% --- Executes during object creation, after setting all properties.
function eH_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eH (see GCBO)
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


% --- Executes when user attempts to close figureDerivacaoNumerica.
function figureDerivacaoNumerica_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figureDerivacaoNumerica (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
%delete(hObject);

pbLimpar_Callback(hObject, eventdata, handles);                             % Limpar toda a informação
set(handles.figureDerivacaoNumerica,'Visible','Off');                       % Esconder a figura

function atualizarGrelha(handles)
grelha = get(handles.cbGrelha, 'Value');
if grelha
    grid on;
else
    grid off;
end

% --- Função auxiliar associada ao botão Atualizar.
function MyAtualizar(handles)
% handles estrutura de dados com as handles para os objetos...

axes(handles.axesGrafico);                                                  % Faz com que o sistema de eixos ativo seja o 'axesGrafico'
cla reset;                                                                  % Limpa os valores do grafico
set(handles.uitabela, 'Data', {});                                          % Limpa os valores da tabela
set(handles.uitabela,'ColumnName',{});                                      % Limpa os nomes da tabela

syms x;
strF = get(handles.tFuncao,'String');
f = @(x) eval(vectorize(char(strF)));
df = diff(f(x));
ddf = diff(diff(f(x)));
a = str2num(get(handles.eA,'String'));
h = str2num(get(handles.eH,'String'));
b = str2num(get(handles.eB,'String'));

escolhabg = get(handles.bgFormulasDNumerica, 'SelectedObject');
escolha=find([handles.rbDFP,...
              handles.rbDFR,...
              handles.rbDFP3,...
              handles.rbDFR3,...
              handles.rbDFC,...
              handles.rbD2,...
              handles.rbTodas]==escolhabg);
todas = 0;
deriv2 = 0;


% Criação das Excepções (Mensagens de erro)
testeFunc=MException('MATLAB:MyAtualizar:badFunc',....
                     'Introduza uma função em x');
testeA=MException('MATLAB:MyAtualizar:badNReal',....
                     'Valor de "a" não introduzido ou não real');
testeB=MException('MATLAB:MyAtualizar:badNReal',....
                     'Valor de "b" não introduzido ou não real');
testeBA=MException('MATLAB:MyAtualizar:badNReal',....
                     'Valor de "b" tem de ser superior a "a"');
testeH=MException('MATLAB:MyAtualizar:badNReal',....
                     'Valor de "h" não introduzido ou não real');

try  
    % validações
    try                                                                     % Try serve para apanhar possiveis erros, sem crashar o programa
           fTeste=f(sym('x'));                                              % Verifica se a função é em 't' e/ou em 'y'
    catch
           throw(testeFunc);                                                % Caso a verificação falhe chama a Excepção 'testeFunc'
    end 
    
    if ~(isscalar(a) && isreal(a)), throw(testeA); end                      % Se 'a' não for um número e se não for um numero real chama a Excepção 'testeA'
    if ~(isscalar(b) && isreal(b)), throw(testeB); end                      % Se 'b' não for um número e se não for um numero real chama a Excepção 'testeB'
    if (a>b), throw(testeBA); end                                           % Se 'a' for maior que 'b' chama a Excepção 'testeBA'
    if ~(isscalar(h) && isreal(h)), throw(testeH); end                      % Se 'h' não for um número e se não for um numero real chama a Excepção 'testeH'
    
switch escolha
    case 1 % Progressivas
        [x,y,dydx]=NDerivacaoDFP(f,a,b,h);
    case 2 % Regressivas
        [x,y,dydx]=NDerivacaoDFR(f,a,b,h);
    case 3 % Progressivas (3 pontos)
        [x,y,dydx]=NDerivacaoDFP3(f,a,b,h);
    case 4 % Regressivas (3 pontos)
        [x,y,dydx]=NDerivacaoDFR3(f,a,b,h);
    case 5 % Centradas (3 pontos)
        [x,y,dydx]=NDerivacaoDFC(f,a,b,h);
    case 6 % 2º Derivada (3 pontos)
        [x,y,dydx]=NDerivacaoD2(f,a,b,h);
        deriv2 = 1;
    case 7 % Todas
        todas = 1;
end

set(handles.uitabela,'Visible','on');                                       % Mostra a tabela
set(handles.axesGrafico,'Visible','on');                                    % Mostra o grafico

if ~todas
    if deriv2                                                               % Se deriv2 já nao for zero, quer dizer que estamos na 2º derivada
        dydxExata = eval(ddf);
    else
        dydxExata = eval(df);                                               % Derivada Exata / Segunda Derivada Exata
    end
    
    erro = abs(dydxExata-dydx);
    
    plot(x,y,'-bo');
    hold on;
    plot(x,dydxExata,'-ks');
    plot(x,dydx,'-r+');
    
    if deriv2                                                               % Se deriv2 já nao for zero, quer dizer que estamos na 2º derivada
        legend('Função', 'Segunda Deriv. Exata', 'Segunda Deriv. Aprox.');
    else
        legend('Função', 'Derivada Exata', 'Derivada Aproximada');
    end
    
    set(handles.uitabela,'ColumnName',[{'x'}, {'y'}, {'DExata'}, {'DNumerica'}, {'Erro'}]);
    if length(dydxExata) == 1
        dydxExata = dydxExata * ones(1,length(x));
    end
    set(handles.uitabela,'Data',num2cell([x.', y.', dydxExata.', dydx.', erro.']));
else
    [x,y,dydxDFP]=NDerivacaoDFP(f,a,b,h);
    [~,~,dydxDFR]=NDerivacaoDFR(f,a,b,h);
    [~,~,dydxDFP3]=NDerivacaoDFP3(f,a,b,h);
    [~,~,dydxDFR3]=NDerivacaoDFR3(f,a,b,h);
    [~,~,dydxDFC]=NDerivacaoDFC(f,a,b,h);
    [~,~,dydxD2]=NDerivacaoD2(f,a,b,h);
    
    dydxExata = eval(df);                                                   % Derivada Exata
    
    if length(dydxExata) == 1                                               % Se a derivada exata for constante, o MATLAB reduz o vetor a apenas um elemento
        dydxExata = dydxExata + zeros(1,length(x));                         % Vetor do tamanho do vetor das abcissas, em que todos os elementos têm o mesmo valor
    end
    
    erroDFP = abs(dydxExata-dydxDFP);
    erroDFR = abs(dydxExata-dydxDFR);
    erroDFP3 = abs(dydxExata-dydxDFP3);
    erroDFR3 = abs(dydxExata-dydxDFR3);
    erroDFC = abs(dydxExata-dydxDFC);
    erroD2 = abs(dydxExata-dydxD2);
    
    plot(x,y,'-bo');
    hold on;
    plot(x,dydxExata,'-ks');
    
    plot(x,dydxDFP,'-r+');
    plot(x,dydxDFR,'-g*');
    plot(x,dydxDFP3,'-m.');
    plot(x,dydxDFR3,'-cd');
    plot(x,dydxDFC,'-yv');
    plot(x,dydxD2,'-rh');
    
    if erroD2
        ddf = diff(diff(f(x)));
        dydxExata2 = eval(df); % Segunda Derivada Exata
    else
        
    end
    legend('Função', 'Exata', 'DFP', 'DFR', 'DFP3', 'DFR3', 'DFC', '2ºD');
    
    set(handles.uitabela,'ColumnName',[{'x'}, {'y'}, {'DExata'},...
        {'DFP'},{'Erro DFP'},...
        {'DFR'}, {'Erro DFR'},...
        {'DFP3'}, {'Erro DFP3'},...
        {'DFR3'}, {'Erro DFR3'},...
        {'DFC'}, {'Erro DFC'},...
        {'2ºD'}, {'Erro 2ºD'},]);
    
    set(handles.uitabela,'Data',num2cell([x.', y.', dydxExata.',...
        dydxDFP.',erroDFP.',...
        dydxDFR.', erroDFR.',...
        dydxDFP3.', erroDFP3.',...
        dydxDFR3.', erroDFR3.',...
        dydxDFC.', erroDFC.',...
        dydxD2.', erroD2.']));
end

hold off;
atualizarGrelha(handles);
catch Me
    errordlg(Me.message,'ERRO','modal')
end

% --- Executes on button press in cbGrelha.
function cbGrelha_Callback(hObject, eventdata, handles)
% hObject    handle to cbGrelha (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbGrelha
atualizarGrelha(handles);


% --- Executes on button press in pbLimpar.
function pbLimpar_Callback(hObject, eventdata, handles)
% hObject    handle to pbLimpar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

set(handles.eA,'String','-2*pi');                                           % Coloca o edit text 'eA' no default
set(handles.eH,'String','0.2');                                             % Coloca o edit text 'eH' no default
set(handles.eB,'String','2*pi');                                            % Coloca o edit text 'eB' no default
set(handles.rbDFP,'Value',1);

set(handles.uitabela, 'Data', {});                                          % Limpa os valores da tabela
set(handles.uitabela,'ColumnName',{});                                      % Limpa os nomes da tabela
set(handles.uitabela,'Visible','off');                                      % Esconde a tabela

cla reset;
set(handles.axesGrafico,'Visible','off');
