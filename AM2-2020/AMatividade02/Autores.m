%Autores - Mostra os Autores do programa
% 
%   03/03/2020 - ArmÃ©nioCorreia .: armenioc@isec.pt 
%   22/04/2020 - Carlos Pais .: a2010017171@isec.pt
%   22/04/2020 - JosÃ© Almeida .: a2019129077@isec.pt
%   22/04/2020 - Pedro Rodrigues .: a2019136525@isec.pt
%%

function varargout = Autor(varargin)
% AUTOR M-file for Autor.fig
%      AUTOR, by itself, creates a new AUTOR or raises the existing
%      singleton*.
%
%      H = AUTOR returns the handle to a new AUTOR or the handle to
%      the existing singleton*.
%
%      AUTOR('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in AUTOR.M with the given input arguments.
%
%      AUTOR('Property','Value',...) creates a new AUTOR or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Autor_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Autor_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Autor

% Last Modified by GUIDE v2.5 27-Apr-2020 15:20:32

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Autor_OpeningFcn, ...
                   'gui_OutputFcn',  @Autor_OutputFcn, ...
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


% --- Executes just before Autor is made visible.
function Autor_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Autor (see VARARGIN)

% Choose default command line output for Autor
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);


I=imread('img_CarlosPais.JPG','JPEG');                  % Procura a imagem com o nome 'img_CarlosPais' e coloca em 'I'
imshow(I,[],'Parent',handles.axesCarlos);               % Mostra a imagem guardada em I, no sistema de eixos 'axesCarlos'

I=imread('img_JoseAlmeida.JPG','JPEG');                 % Procura a imagem com o nome 'img_JoseAlmeida' e coloca em 'I'
imshow(I,[],'Parent',handles.axesJose);                 % Mostra a imagem guardada em I, no sistema de eixos 'axesJose'

I=imread('img_PedroRodrigues.JPG','JPG');               % Procura a imagem com o nome 'img_PedroRodrigues' e coloca em 'I'
imshow(I,[],'Parent',handles.axesPedro);                % Mostra a imagem guardada em I, no sistema de eixos 'axesPedro'


% UIWAIT makes Autor wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Autor_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
SN = questdlg('Quer mesmo sair?','SAIR','Sim','Não','Sim');                 % abre uma mensagem a perguntar ao utilizador 'Quer mesmo sair?'
if strcmp(SN,'Não')                                                         % caso o utilizador escolha a opção não, então a figura 'Autores' mantém-se aberta
    return 
end
delete(hObject);                                                            % senão, apaga a figura