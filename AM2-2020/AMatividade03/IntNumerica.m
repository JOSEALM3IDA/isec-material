function varargout = IntNumerica(varargin)
% INTNUMERICA MATLAB code for IntNumerica.fig
%      INTNUMERICA, by itself, creates a new INTNUMERICA or raises the existing
%      singleton*.
%
%      H = INTNUMERICA returns the handle to a new INTNUMERICA or the handle to
%      the existing singleton*.
%
%      INTNUMERICA('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in INTNUMERICA.M with the given input arguments.
%
%      INTNUMERICA('Property','Value',...) creates a new INTNUMERICA or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before IntNumerica_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to IntNumerica_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help IntNumerica

% Last Modified by GUIDE v2.5 03-Jun-2020 18:45:22

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @IntNumerica_OpeningFcn, ...
                   'gui_OutputFcn',  @IntNumerica_OutputFcn, ...
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


% --- Executes just before IntNumerica is made visible.
function IntNumerica_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to IntNumerica (see VARARGIN)


% Choose default command line output for IntNumerica
handles.output = hObject;
set(hObject,'Name','Integracao Numerica');

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes IntNumerica wait for user response (see UIRESUME)
% uiwait(handles.figure1);

pbLimpar_Callback(hObject, eventdata, handles)

clear
clc

% --- Outputs from this function are returned to the command line.
function varargout = IntNumerica_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pbCalcular.
function pbCalcular_Callback(hObject, eventdata, handles)
% hObject    handle to pbCalcular (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
MyAtualizar(hObject, eventdata, handles);

% --- Executes on button press in cbGrelha.
function cbGrelha_Callback(hObject, eventdata, handles)
% hObject    handle to cbGrelha (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbGrelha
t1 = get(handles.pResult,'Visible');
t2 = get(handles.pTodos,'Visible');

% Verificar se o botao Calcular ja foi usado (pelo menos um dos resultados visivel)
if strcmp(t1,'on') || strcmp(t2,'on')
    grelha = get(handles.cbGrelha,'Value');
    if grelha == 1
        grid on;
    else
        grid off;
    end
end

% --- Executes on button press in cbLegenda.
function cbLegenda_Callback(hObject, eventdata, handles)
% hObject    handle to cbLegenda (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbLegenda
t1 = get(handles.pResult,'Visible');
t2 = get(handles.pTodos,'Visible');

% Verificar se o botao Calcular ja foi usado (pelo menos um dos resultados visivel)
if strcmp(t1,'on') || strcmp(t2,'on')
    if get(handles.cbLegenda, 'Value')
        legend('show');
    else
        legend('hide');
    end
end


% --- Executes on button press in cbLEixos.
function cbLEixos_Callback(hObject, eventdata, handles)
% hObject    handle to cbLEixos (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbLEixos

t1 = get(handles.pResult,'Visible');
t2 = get(handles.pTodos,'Visible');

% Verificar se o botao Calcular ja foi usado (pelo menos um dos resultados visivel)
if strcmp(t1,'on') || strcmp(t2,'on')
    if get(handles.cbLEixos, 'Value')
        xlabel('x')
        ylabel('y')
    else
        xlabel('')
        ylabel('')
    end
end


% --- Executes on button press in cbPArea.
function cbPArea_Callback(hObject, eventdata, handles)
% hObject    handle to cbPArea (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of cbPArea


t1 = get(handles.pResult,'Visible');
t2 = get(handles.pTodos,'Visible');

% Verificar se o botao Calcular ja foi usado (pelo menos um dos resultados visivel)
if strcmp(t1,'on') || strcmp(t2,'on')
    a  = str2num(get(handles.eA,'String'));                                 % Obtem a string existente no edit text 'eA', converte para numero e coloca em 'a'
    b  = str2num(get(handles.eB,'String'));                                 % Obtem a string existente no edit text 'eB', converte para numero e coloca em 'b'
    n  = str2num(get(handles.eN,'String'));                                 % Obtem a string existente no edit text 'eN', converte para numero e coloca em 'n'

    strF = get(handles.stFuncao,'String');                                  % Obtem a string existente no edit text 'eF' e coloca em strF
    f=@(x) eval(vectorize(char(strF)));                                     % Converte a string num function handle

    h = (b-a)/n;
    x=a:h:b;
    y = f(x);

    A=area(x,y);
    A.FaceColor='r';
    legend('Área');

    preencher = get(handles.cbPArea, 'Value');
    if preencher
        A.FaceAlpha = 1;
        A.EdgeAlpha = 1;
        
    else
        A.FaceAlpha = 0;
        A.EdgeAlpha = 0;
        plot(x,y);
        legend('Função');
    end
    cbGrelha_Callback(hObject, eventdata, handles);
    cbLEixos_Callback(hObject, eventdata, handles);
    cbLegenda_Callback(hObject, eventdata, handles)
end


% --- Executes on button press in rbSimpson.
function rbSimpson_Callback(hObject, eventdata, handles)
% hObject    handle to rbSimpson (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rbSimpson


% --- Executes on button press in rbTrapezios.
function rbTrapezios_Callback(hObject, eventdata, handles)
% hObject    handle to rbTrapezios (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rbTrapezios


% --- Executes on button press in rbSubInt.
function rbSubInt_Callback(hObject, eventdata, handles)
% hObject    handle to rbSubInt (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rbSubInt
set(handles.eErro,'Enable','off');                                          % Coloca o campo 'eErro' nao editavel
set(handles.eN,'Enable','on');                                              % Coloca o campo 'eN' editavel


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



function eErro_Callback(hObject, eventdata, handles)
% hObject    handle to eErro (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eErro as text
%        str2double(get(hObject,'String')) returns contents of eErro as a double


% --- Executes during object creation, after setting all properties.
function eErro_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eErro (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in rbErroMax.
function rbErroMax_Callback(hObject, eventdata, handles)
% hObject    handle to rbErroMax (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rbErroMax
set(handles.eN,'Enable','off');                                             % Coloca o campo 'eN' nao editavel
set(handles.eErro,'Enable','on');                                           % Coloca o campo 'eErro' editavel


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

function MyAtualizar(hObject, eventdata, handles)

strF = get(handles.stFuncao,'String');                                      % Obtem a string existente no edit text 'eF' e coloca em strF
f=@(x) eval(vectorize(char(strF)));

a = str2num(get(handles.eA,'String'));                                      % Obtem a string existente no edit text 'eA', converte para numero e coloca em 'a'
b = str2num(get(handles.eB,'String'));                                      % Obtem a string existente no edit text 'eB', converte para numero e coloca em 'b'
n = str2num(get(handles.eN,'String'));                                      % Obtem a string existente no edit text 'eN', converte para numero e coloca em 'n'
escolhaMIntNum=get(handles.bgMIntNum,'SelectedObject');
escolhaMIN=find([handles.rbTrapezios,...
              handles.rbSimpson,...
              handles.rbQuad,...
              handles.rbTodos]==escolhaMIntNum);
TRAPEZIOS=1;
SIMPSON=2;
QUAD=3;
TODOS=4;


% Criacao das Excecoes (Mensagens de erro)
testeFunc=MException('MATLAB:MyAtualizar:badFunc',...
                     'Introduza uma funcao em x');
testeA=MException('MATLAB:MyAtualizar:badNReal',...
                     'Valor de "a" nao introduzido ou nao real');
testeB=MException('MATLAB:MyAtualizar:badNReal',...
                     'Valor de "b" nao introduzido ou nao real');
testeBA=MException('MATLAB:MyAtualizar:badNReal',...
                     'Valor de "b" tem de ser superior a "a"');
testeN=MException('MATLAB:MyAtualizar:badNReal',...
                     'Introduza "n" inteiro e maior que zero!');
testeE=MException('MATLAB:MyAtualizar:badNReal',...
                     'Valor de "E" nao introduzido ou nao real');
                 
syms x;
try  
    % validacoes
    try                                                                     % Try serve para apanhar possiveis erros, sem crashar o programa
           fTeste=f(sym('x'));                                              % Verifica se a funcao esta em ordem a 'x'
    catch
           throw(testeFunc);                                                % Caso a verificacao falhe chama a Excecao 'testeFunc'
    end 
    
    if ~(isscalar(a) && isreal(a)), throw(testeA); end                      % Se 'a' nao for um namero e se nao for um numero real chama a Excecao 'testeA'
    if ~(isscalar(b) && isreal(b)), throw(testeB); end                      % Se 'b' nao for um namero e se nao for um numero real chama a Excecao 'testeB'
    if (a>b), throw(testeBA); end                                           % Se 'a' for maior que 'b' chama a Excecao 'testeBA'

    h = (b-a)/n;
    t=a:h:b;
    y=f(t);
    
    % Grafico
    plot(t,y);
    legend('Função');
    legend('hide');
    shg;
    
    % Solucao Exata
    exata = double(int(f(sym('x')),a,b));

    % Switch case que vai executar segundo as escolhas dos utilizadores
    sTodos = 0;
    switch escolhaMIN
        case TRAPEZIOS                                                      % Caso a escolha do utilizador seja a Regra dos Trapezios
            A = INumRTrapezios(f,a,b,n);                                    % 'A' trata-se da aproximacao do valor da area, e 'erro' o erro maximo dessa aproximacao
        case SIMPSON                                                        % Caso a escolha do utilizador seja a regra de Simpson
            A = INumRSimpson(f,a,b,n);                                      
        case QUAD                                                           % Caso a escolha do utilizador seja Quad
            A = quad(f,a,b);
        case TODOS                                                          % Caso a escolha do utilizador seja Todos
            sTodos = 1;
            
            set(handles.pResult,'Visible','off');
            set(handles.pTodos,'Visible','on');
            
            % Exata
            set(handles.st2Exata,'String',num2str(exata));
            
            % Regra dos Trapezios
            A = INumRTrapezios(f,a,b,n);
            set(handles.stTrap,'String',num2str(A));
            erro = A-exata;
            set(handles.stETrap,'String',num2str(erro));
            
            % Regra de Simpson
            A = INumRSimpson(f,a,b,n);
            set(handles.stSimp,'String',num2str(A));
            erro = A-exata;
            set(handles.stESimp,'String',num2str(erro));
            
            % Quad (MATLAB)
            A = quad(f,a,b);
            set(handles.stQuad,'String',num2str(A));
            erro = A-exata;
            set(handles.stEQuad,'String',num2str(erro));
    end
    
    if ~sTodos
        set(handles.pTodos,'Visible','off');
        set(handles.pResult,'Visible','on');
        
        % Erro
        erro = A-exata;

        set(handles.stAprox,'String',num2str(A));
        set(handles.stExata,'String',num2str(exata));
        set(handles.stErro,'String',num2str(erro));
    end
    
    cbLegenda_Callback(hObject, eventdata, handles);
    cbPArea_Callback(hObject, eventdata, handles);
    cbLEixos_Callback(hObject, eventdata, handles);
    cbGrelha_Callback(hObject, eventdata, handles);
    
catch Me
    errordlg(Me.message,'ERRO','modal')
end



% --- Executes on button press in pbLimpar.
function pbLimpar_Callback(hObject, eventdata, handles)
% hObject    handle to pbLimpar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

set(handles.eA,'String','0');                                               % Coloca o edit text 'eA' no default
set(handles.eB,'String','5');                                               % Coloca o edit text 'eB' no default
set(handles.eN,'String','20');                                              % Coloca o edit text 'eN' no default

set(handles.pResult,'Visible','off');
set(handles.pTodos,'Visible','off');

set(handles.rbTrapezios,'Value',1);

set(handles.cbGrelha,'Value',0);
cbGrelha_Callback(hObject, eventdata, handles)

set(handles.cbPArea,'Value',0);
cbPArea_Callback(hObject, eventdata, handles)

set(handles.cbLegenda,'Value',0);
cbLegenda_Callback(hObject, eventdata, handles)

set(handles.cbLEixos,'Value',0);
cbLEixos_Callback(hObject, eventdata, handles)

cla reset;
set(handles.axesGrafico,'Visible','off');
 


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
pbLimpar_Callback(hObject, eventdata, handles);                             % Limpar toda a informação
set(handles.figure1,'Visible','Off');                                       % Esconder a figura