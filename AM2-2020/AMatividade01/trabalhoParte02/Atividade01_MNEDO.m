%Atividade01_MNEDO - GUI onde o programa deve ser iniciado
% 
%   03/03/2020 - ArménioCorreia .: armenioc@isec.pt 
%   22/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   22/04/2020 - José Almeida .: a2019129077@isec.pt
%   22/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function varargout = Atividade01_MNEDO(varargin)
% ATIVIDADE01_MNEDO M-file for Atividade01_MNEDO.fig
%      ATIVIDADE01_MNEDO, by itself, creates a new ATIVIDADE01_MNEDO or raises the existing
%      singleton*.
%
%      H = ATIVIDADE01_MNEDO returns the handle to a new ATIVIDADE01_MNEDO or the handle to
%      the existing singleton*.
%
%      ATIVIDADE01_MNEDO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in ATIVIDADE01_MNEDO.M with the given input arguments.
%
%      ATIVIDADE01_MNEDO('Property','Value',...) creates a new ATIVIDADE01_MNEDO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Atividade01_MNEDO_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Atividade01_MNEDO_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Atividade01_MNEDO

% Last Modified by GUIDE v2.5 23-Apr-2020 23:53:03
% Arménio Correia .: armenioc@isec.pt

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Atividade01_MNEDO_OpeningFcn, ...
                   'gui_OutputFcn',  @Atividade01_MNEDO_OutputFcn, ...
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


% --- Executes just before Atividade01_MNEDO is made visible.
function Atividade01_MNEDO_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Atividade01_MNEDO (see VARARGIN)

% Choose default command line output for Atividade01_MNEDO
handles.output = hObject;
set(hObject,'Name','Atividade01: Menu Inicial'); 

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Atividade01_MNEDO wait for user response (see UIRESUME)
% uiwait(handles.figurePrincipal);


% --- Outputs from this function are returned to the command line.
function varargout = Atividade01_MNEDO_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pb_IntfTexto.
function pb_IntfTexto_Callback(hObject, eventdata, handles)
% hObject    handle to pb_IntfTexto (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
delete(handles.figurePrincipal);                                            % apaga a figura 'figurePrincipal'
Interface();                                                                % abre o ficheiro 'Interface'


% --- Executes on button press in pb_GUI.
function pb_GUI_Callback(hObject, eventdata, handles)
% hObject    handle to pb_GUI (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
delete(handles.figurePrincipal);                                            % apaga a figura 'figurePrincipal'
MaquinaEDO1();                                                              % abre o ficheiro 'MaquinaEDO1'


% --------------------------------------------------------------------
function MAutores_Callback(hObject, eventdata, handles)
% hObject    handle to MAutores (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
Autores();                                                                  % abre o ficheiro 'Autores'


% --------------------------------------------------------------------
function MRelatorio_Callback(hObject, eventdata, handles)
% hObject    handle to MRelatorio (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

%eval(['!' pwd '\Relatorio_Atividade02.pdf'])%Abre o PDF que contém o relatório da actividade
winopen('Relatorio_Atividade01.pdf')                                        % Abre o ficheiro 'Relatoro_Atividade01.pdf'


% --------------------------------------------------------------------
function MDE_Callback(hObject, eventdata, handles)
% hObject    handle to MDE (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
web('http://www.mathworks.com/products/matlab/examples.html?file=/products/demos/shipping/matlab/odedemo.html', '-browser')  % Abre a página web no browser


% --------------------------------------------------------------------
function MSair_Callback(hObject, eventdata, handles)
% hObject    handle to MSair (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
SN = questdlg('Quer mesmo sair?','SAIR','Sim','Não','Sim');                 % abre uma mensagem a perguntar ao utilizador 'Quer mesmo sair?'
if strcmp(SN,'Não')                                                         % caso o utilizador escolha a opção não, então a figura 'Autores' mantém-se aberta
    return 
end
delete(handles.figurePrincipal);                                            % senão, apaga a figura
	

% --- Executes when user attempts to close figurePrincipal.
function figurePrincipal_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figurePrincipal (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
% SN = questdlg('Quer sair?', 'Sair','Sim','Não','Sim');
% if strcmp(SN,'Não')
%     return 
% end;
% delete(hObject);
MSair_Callback([],[],handles);                                              % Chama a função 'MSair'


% --------------------------------------------------------------------
function MFile_Callback(hObject, eventdata, handles)
% hObject    handle to MFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
