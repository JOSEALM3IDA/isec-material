function varargout = gui(varargin)
    % GUI MATLAB code for gui.fig
    %      GUI, by itself, creates a new GUI or raises the existing
    %      singleton*.
    %
    %      H = GUI returns the handle to a new GUI or the handle to
    %      the existing singleton*.
    %
    %      GUI('CALLBACK',hObject,eventData,handles,...) calls the local
    %      function named CALLBACK in GUI.M with the given input arguments.
    %
    %      GUI('Property','Value',...) creates a new GUI or raises the
    %      existing singleton*.  Starting from the left, property value pairs are
    %      applied to the GUI before gui_OpeningFcn gets called.  An
    %      unrecognized property name or invalid value makes property application
    %      stop.  All inputs are passed to gui_OpeningFcn via varargin.
    %
    %      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
    %      instance to run (singleton)".
    %
    % See also: GUIDE, GUIDATA, GUIHANDLES

    % Edit the above text to modify the response to help gui

    % Last Modified by GUIDE v2.5 27-Jun-2021 00:04:05

    % Begin initialization code - DO NOT EDIT
    gui_Singleton = 1;
    gui_State = struct('gui_Name',       mfilename, ...
                       'gui_Singleton',  gui_Singleton, ...
                       'gui_OpeningFcn', @gui_OpeningFcn, ...
                       'gui_OutputFcn',  @gui_OutputFcn, ...
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
end

% --- Executes just before gui is made visible.
function gui_OpeningFcn(hObject, eventdata, handles, varargin)
    % This function has no output args, see OutputFcn.
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    % varargin   command line arguments to gui (see VARARGIN)
    
    handles.IMG_RES = [28 28];
    
    handles.hasNet = 0;
    set(findall(handles.PANEL_SIM_DATASET, '-property', 'enable'), 'enable', 'off');
    set(findall(handles.PANEL_SIM_CHAR, '-property', 'enable'), 'enable', 'off');
    set(handles.TEXT_CRECONHECIDO, 'visible', 'off');

    % Choose default command line output for gui
    handles.output = hObject;

    % Update handles structure
    guidata(hObject, handles);

    % UIWAIT makes gui wait for user response (see UIRESUME)
    % uiwait(handles.figure1);
end

% --- Outputs from this function are returned to the command line.
function varargout = gui_OutputFcn(hObject, eventdata, handles) 
    % varargout  cell array for returning output args (see VARARGOUT);
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Get default command line output from handles structure
    varargout{1} = handles.output;
end

% --------------------------------------------------------------------
function LOAD_NN_MENU_Callback(hObject, eventdata, handles)
    % hObject    handle to LOAD_NN_MENU (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    [fName, fPath] = uigetfile;
    
    if (fName == 0)
        return;
    end
    
    if (fPath == 0)
        return;
    end
    
    netFileStr = strcat(fPath, fName);
    handles.net = load(netFileStr, 'net').net;
    
    handles.hasNet = 1;
    set(findall(handles.PANEL_SIM_DATASET, '-property', 'enable'), 'enable', 'on');
    set(findall(handles.PANEL_SIM_CHAR, '-property', 'enable'), 'enable', 'on');
    set(handles.BTN_NETSIM_DRAWING, 'enable', 'off');
    
    % Update handles structure
    guidata(hObject, handles);
end


% --- Executes on selection change in PUP_TRAINFCN.
function PUP_TRAINFCN_Callback(hObject, eventdata, handles)
    % hObject    handle to PUP_TRAINFCN (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: contents = cellstr(get(hObject,'String')) returns PUP_TRAINFCN contents as cell array
    %        contents{get(hObject,'Value')} returns selected item from PUP_TRAINFCN
end

% --- Executes during object creation, after setting all properties.
function PUP_TRAINFCN_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to PUP_TRAINFCN (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: popupmenu controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end


function EDIT_NNCFG_Callback(hObject, eventdata, handles)
    % hObject    handle to EDIT_NNCFG (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of EDIT_NNCFG as text
    %        str2double(get(hObject,'String')) returns contents of EDIT_NNCFG as a double
end

% --- Executes during object creation, after setting all properties.
function EDIT_NNCFG_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to EDIT_NNCFG (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end


function EDIT_ACTIVATIONFCN_Callback(hObject, eventdata, handles)
    % hObject    handle to EDIT_ACTIVATIONFCN (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of EDIT_ACTIVATIONFCN as text
    %        str2double(get(hObject,'String')) returns contents of EDIT_ACTIVATIONFCN as a double
end

% --- Executes during object creation, after setting all properties.
function EDIT_ACTIVATIONFCN_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to EDIT_ACTIVATIONFCN (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end

% --------------------------------------------------------------------
function SAVE_NN_MENU_Callback(hObject, eventdata, handles)
    % hObject    handle to SAVE_NN_MENU (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    if (handles.hasNet ~= 1)
        errordlg('Não existe uma rede para gravar!','ERRO');
        return;
    end
    
    [fName, fPath] = uiputfile('*.mat', 'Gravar Neural Network');
    
    if (fName == 0)
        return;
    end
    
    if (fPath == 0)
        return;
    end

    net = handles.net;
    
    save(sprintf("%s\\%s", fPath, fName), 'net');
end


% --- Executes on button press in BTN_NETCREATETRAIN.
function BTN_NETCREATETRAIN_Callback(hObject, eventdata, handles)
    % hObject    handle to BTN_NETCREATETRAIN (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    if (isempty(get(handles.EDIT_NNCFG, 'String')))
        errordlg('O campo "Topologia" não pode estar vazio!','ERRO');
        return;
    end
    
    if (isempty(get(handles.EDIT_ACTIVATIONFCN, 'String')))
        errordlg('O campo "Funções de Ativação" não pode estar vazio!','ERRO');
        return;
    end
    
    if (isempty(get(handles.EDIT_TRAINFOLDER, 'String')))
        errordlg('O campo "Pasta para Treino" não pode estar vazio!','ERRO');
        return;
    end
    
    divTrainStr = get(handles.EDIT_DIVTRAIN, 'String');
    divValStr = get(handles.EDIT_DIVVAL, 'String');
    divTestStr = get(handles.EDIT_DIVTEST, 'String');
    
    if (~isreal(divTrainStr) || ~isreal(divValStr) || ~isreal(divTestStr))
        errordlg('Os parâmetros train, val e test têm de ser números reais!','ERRO');
        return;
    end
    
    divTrain = str2num(divTrainStr);
    divVal = str2num(divValStr);
    divTest = str2num(divTestStr);
    
    trainFcnCell = get(handles.PUP_TRAINFCN, 'String');
    trainFcnCell = trainFcnCell(get(handles.PUP_TRAINFCN, 'Value'));
    trainFcnStr = cell2mat(trainFcnCell);
    
    if (strcmp(trainFcnStr, 'divideind') == 0)
        if (divTrain < 0 || divVal < 0 || divTest < 0)
            errordlg('Os parâmetros train, val e test devem ser maiores ou iguais a 0!','ERRO');
            return;
        end
        
        if ((divTrain + divVal + divTest) ~= 1)
            errordlg('Para essa função de divisão, os parâmetros train, val e test somados têm de ser igual a 1!','ERRO');
            return;
        end
    end
    
    nnCfgCellArray = split(get(handles.EDIT_NNCFG, 'String'));
    
    for i = 1: length(nnCfgCellArray)
        if (~isscalar(nnCfgCellArray(i)))
            errordlg('O número de neurónios por camada deve ser inteiro!', 'ERRO');
            return;
        end
    end
    
    for i = 1: length(nnCfgCellArray)
        nnCfgValue(i) = str2double([nnCfgCellArray{i, :}]');
        
        if (nnCfgValue(i) <= 0)
            errordlg('A topologia tem que ser composta por valores positivos!', 'ERRO');
            return;
        end
    end
    
    handles.net = feedforwardnet(nnCfgValue);
    
    handles.net.trainFcn = trainFcnStr;
    
    divFcnCell = get(handles.PUP_DIVIDEFCN, 'String');
    divFcnCell = divFcnCell(get(handles.PUP_DIVIDEFCN, 'Value'));
    divFcnStr = cell2mat(divFcnCell);
    
    handles.net.divideFcn = divFcnStr;
    
    handles.net.divideParam.trainRatio = divTrain;
    handles.net.divideParam.valRatio = divVal;
    handles.net.divideParam.testRatio = divTest;
    
    activationFcnCellArray = split(get(handles.EDIT_ACTIVATIONFCN, 'String'));
    activationFcnStrArray = string(activationFcnCellArray);
    
    if (length(activationFcnStrArray) ~= (length(nnCfgValue) + 1))
        errordlg('O número de funções de ativação deve ser igual ao número de hidden layers + 1!','ERRO');
        return;
    end
    
    for i = 1: length(activationFcnStrArray)
        try 
            handles.net.layers{i}.transferFcn = activationFcnStrArray(i);
        catch
            errordlg(sprintf('Função de ativação inválida: %s!', activationFcnStrArray(i)),'ERRO');
            return;
        end
    end
    
    folderImg = dir(sprintf("%s\\*.jpg", get(handles.EDIT_TRAINFOLDER, 'String')));
    imgFiles = natsort({folderImg.name});
    
    if (isempty(imgFiles))
        errordlg('Não existem imagens com o formato correto nessa pasta!','ERRO');
        return;
    end

    letrasBW = zeros(handles.IMG_RES(1) * handles.IMG_RES(1), length(imgFiles));
    letrasTarget = [];
    letrasBWCol = 1;
    
    jump = length(imgFiles) / 10;

    for i = 1: jump
        for j = 1: 10
            img = imread(sprintf('%s\\%s', get(handles.EDIT_TRAINFOLDER, 'String'), char(imgFiles(((j - 1) * jump) + i))));
%             imshow(img);
%             pause(0.05);
            img = imresize(img, handles.IMG_RES);
            binarizedImg = imbinarize(img);
            letrasBW(:, letrasBWCol) = reshape(binarizedImg, 1, []);
            letrasBWCol = letrasBWCol + 1;
        end

        letrasTarget = [letrasTarget eye(10)];
    end
    
    if (get(handles.ordemMenuTrain, 'Value') == 2)
        letrasTarget = flip(letrasTarget, 1);
    end
    
    try
        [handles.net, ~] = train(handles.net, letrasBW, letrasTarget);
    catch
        errordlg('Erro desconhecido ao treinar!','ERRO');
        return;
    end
    out = sim(handles.net, letrasBW);
    
    handles.hasNet = 1;
    set(findall(handles.PANEL_SIM_DATASET, '-property', 'enable'), 'enable', 'on');
    set(findall(handles.PANEL_SIM_CHAR, '-property', 'enable'), 'enable', 'on');
    set(handles.BTN_NETSIM_DRAWING, 'enable', 'off');
    
    figure;
    plotconfusion(letrasTarget, out, 'Train -'); 
    
    % Update handles structure
    guidata(hObject, handles);
end


% --- Executes on button press in BTN_CHOOSEDIRTRAIN.
function BTN_CHOOSEDIRTRAIN_Callback(hObject, eventdata, handles)
    % hObject    handle to BTN_CHOOSEDIRTRAIN (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    set(handles.EDIT_TRAINFOLDER, 'String', uigetdir('.', "Escolher pasta para treino"));
    
    if (get(handles.EDIT_TRAINFOLDER, 'String') == '0')
        set(handles.EDIT_TRAINFOLDER, 'String', 'C:\');
    end
end


function EDIT_TRAINFOLDER_Callback(hObject, eventdata, handles)
    % hObject    handle to EDIT_TRAINFOLDER (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of EDIT_TRAINFOLDER as text
    %        str2double(get(hObject,'String')) returns contents of EDIT_TRAINFOLDER as a double
end

% --- Executes during object creation, after setting all properties.
function EDIT_TRAINFOLDER_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to EDIT_TRAINFOLDER (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end


% --- Executes on selection change in ordemMenuTrain.
function ordemMenuTrain_Callback(hObject, eventdata, handles)
    % hObject    handle to ordemMenuTrain (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: contents = cellstr(get(hObject,'String')) returns ordemMenuTrain contents as cell array
    %        contents{get(hObject,'Value')} returns selected item from ordemMenuTrain
end

% --- Executes during object creation, after setting all properties.
function ordemMenuTrain_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to ordemMenuTrain (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: popupmenu controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end


% --- Executes on selection change in PUP_DIVIDEFCN.
function PUP_DIVIDEFCN_Callback(hObject, eventdata, handles)
    % hObject    handle to PUP_DIVIDEFCN (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: contents = cellstr(get(hObject,'String')) returns PUP_DIVIDEFCN contents as cell array
    %        contents{get(hObject,'Value')} returns selected item from PUP_DIVIDEFCN
end

% --- Executes during object creation, after setting all properties.
function PUP_DIVIDEFCN_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to PUP_DIVIDEFCN (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: popupmenu controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end


function EDIT_DIVTRAIN_Callback(hObject, eventdata, handles)
    % hObject    handle to EDIT_DIVTRAIN (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of EDIT_DIVTRAIN as text
    %        str2double(get(hObject,'String')) returns contents of EDIT_DIVTRAIN as a double
end

% --- Executes during object creation, after setting all properties.
function EDIT_DIVTRAIN_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to EDIT_DIVTRAIN (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end


function EDIT_DIVVAL_Callback(hObject, eventdata, handles)
    % hObject    handle to EDIT_DIVVAL (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of EDIT_DIVVAL as text
    %        str2double(get(hObject,'String')) returns contents of EDIT_DIVVAL as a double
end

% --- Executes during object creation, after setting all properties.
function EDIT_DIVVAL_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to EDIT_DIVVAL (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end


function EDIT_DIVTEST_Callback(hObject, eventdata, handles)
    % hObject    handle to EDIT_DIVTEST (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of EDIT_DIVTEST as text
    %        str2double(get(hObject,'String')) returns contents of EDIT_DIVTEST as a double
end

% --- Executes during object creation, after setting all properties.
function EDIT_DIVTEST_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to EDIT_DIVTEST (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end


% --- Executes on button press in BTN_NETSIM_DATASET.
function BTN_NETSIM_DATASET_Callback(hObject, eventdata, handles)
    % hObject    handle to BTN_NETSIM_DATASET (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    folderImg = dir(sprintf("%s\\*.jpg", get(handles.EDIT_SIMFOLDER, 'String')));
    imgFiles = natsort({folderImg.name});
    
    if (isempty(imgFiles))
        errordlg('Não existem imagens com o formato correto nessa pasta!','ERRO');
        return;
    end

    letrasBW = zeros(handles.IMG_RES(1) * handles.IMG_RES(1), length(imgFiles));
    letrasTarget = [];
    letrasBWCol = 1;
    
    jump = length(imgFiles) / 10;

    for i = 1: jump
        for j = 1: 10
            img = imread(sprintf('%s\\%s', get(handles.EDIT_SIMFOLDER, 'String'), char(imgFiles(((j - 1) * jump) + i))));
%             imshow(img);
%             pause(0.05);
            img = imresize(img, handles.IMG_RES);
            binarizedImg = imbinarize(img);
            letrasBW(:, letrasBWCol) = reshape(binarizedImg, 1, []);
            letrasBWCol = letrasBWCol + 1;
        end

        letrasTarget = [letrasTarget eye(10)];
    end
    
    if (get(handles.ordemMenuSim, 'Value') == 2)
        letrasTarget = flip(letrasTarget, 1);
    end
    
    out = sim(handles.net, letrasBW);
    
    figure;
    plotconfusion(letrasTarget, out, 'Simulation w/ Dataset -');
end

% --- Executes on button press in BTN_CHOOSEDIRSIM.
function BTN_CHOOSEDIRSIM_Callback(hObject, eventdata, handles)
    % hObject    handle to BTN_CHOOSEDIRSIM (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    set(handles.EDIT_SIMFOLDER, 'String', uigetdir('.', "Escolher pasta para treino"));
    
    if (get(handles.EDIT_SIMFOLDER, 'String') == '0')
        set(handles.EDIT_SIMFOLDER, 'String', 'C:\');
    end
end


function EDIT_SIMFOLDER_Callback(hObject, eventdata, handles)
    % hObject    handle to EDIT_SIMFOLDER (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of EDIT_SIMFOLDER as text
    %        str2double(get(hObject,'String')) returns contents of EDIT_SIMFOLDER as a double
end

% --- Executes during object creation, after setting all properties.
function EDIT_SIMFOLDER_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to EDIT_SIMFOLDER (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end

% --- Executes on selection change in ordemMenuSim.
function ordemMenuSim_Callback(hObject, eventdata, handles)
    % hObject    handle to ordemMenuSim (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: contents = cellstr(get(hObject,'String')) returns ordemMenuSim contents as cell array
    %        contents{get(hObject,'Value')} returns selected item from ordemMenuSim
end

% --- Executes during object creation, after setting all properties.
function ordemMenuSim_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to ordemMenuSim (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: popupmenu controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end


% --- Executes on button press in BTN_CHOOSEFILESIM.
function BTN_CHOOSEFILESIM_Callback(hObject, eventdata, handles)
    % hObject    handle to BTN_CHOOSEFILESIM (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    [fName, fPath] = uigetfile('*.jpg', "Escolher ficheiro para simulação");
    tempStr = sprintf('%s%s', fPath, fName);
    
    set(handles.EDIT_SIMFILE, 'String', tempStr);
    
    if (get(handles.EDIT_SIMFILE, 'String') == '0')
        set(handles.EDIT_SIMFILE, 'String', 'C:\1.jpg');
    end
    
    img = imread(sprintf("%s%s", fPath, fName));
    imshow(img, 'Parent', handles.imgAxes);
end


function EDIT_SIMFILE_Callback(hObject, eventdata, handles)
    % hObject    handle to EDIT_SIMFILE (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of EDIT_SIMFILE as text
    %        str2double(get(hObject,'String')) returns contents of EDIT_SIMFILE as a double
end

% --- Executes during object creation, after setting all properties.
function EDIT_SIMFILE_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to EDIT_SIMFILE (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end
end


% --- Executes on button press in BTN_NETSIM_FILE.
function BTN_NETSIM_FILE_Callback(hObject, eventdata, handles)
    % hObject    handle to BTN_NETSIM_FILE (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    imgFile = get(handles.EDIT_SIMFILE, 'String');

    letrasBW = zeros(handles.IMG_RES(1) * handles.IMG_RES(1), 1);
    
    try
        img = imread(imgFile);
    catch
        errordlg('O ficheiro específicado não existe!','ERRO');
        return;
    end
    
    imshow(img, 'Parent', handles.imgAxes);

    img = imresize(img, [28 28]);
    binarizedImg = imbinarize(img);
    letrasBW(:, 1) = reshape(binarizedImg, 1, []);
    
    out = sim(handles.net, letrasBW);
    
    possibleCharacters = ['α' 'β' 'γ' 'ε' 'η' 'θ' 'π' 'ρ' 'ψ' 'ω'];
    [~, b] = max(out(:, 1));      
    
    set(handles.TEXT_CRECONHECIDO, 'visible', 'on');
    set(handles.STATIC_GUESS, 'String', possibleCharacters(b));
end

% --- Executes on button press in BTN_NETSIM_DRAWING.
function BTN_NETSIM_DRAWING_Callback(hObject, eventdata, handles)
    % hObject    handle to BTN_NETSIM_DRAWING (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    letrasBW = zeros(3024 * 3024 * handles.IMG_RES * handles.IMG_RES, 1);

    binaryImg = createMask(handles.ROI, [28 28]);
    
    boundaries = bwboundaries(binaryImg);
    xy = boundaries{1};
    x = xy(:, 2);
    y = xy(:, 1);
    hold on;
    plot(handles.drawAxes, x, y, 'Color', [0 0 0], 'LineWidth', 15);
    
    disp(findobj(handles.drawAxes, 'Tag', 'letter'))
    figure;
    imshow(handles.drawAxes);
    figure;
    imshow(img);

    img = imresize(img, [28 28]);
    binarizedImg = imbinarize(img);
    letrasBW(:, 1) = reshape(binarizedImg, 1, []);
    
    out = sim(handles.net, letrasBW);
    
    possibleCharacters = ['α' 'β' 'γ' 'ε' 'η' 'θ' 'π' 'ρ' 'ψ' 'ω'];
    [~, b] = max(out(:, 1));      
    
    set(handles.TEXT_CRECONHECIDO, 'visible', 'on');
    set(handles.STATIC_GUESS, 'String', possibleCharacters(b));
end


% --- Executes during object creation, after setting all properties.
function drawAxes_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to drawAxes (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: place code in OpeningFcn to populate drawAxes
    
    set(gca, 'XColor', 'none', 'YColor', 'none');
end


% --- Executes on mouse press over axes background.
function drawAxes_ButtonDownFcn(hObject, eventdata, handles)
    % hObject    handle to drawAxes (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    
    if (strcmp(get(gcf,'SelectionType'), 'alt'))
        cla(handles.drawAxes);
        return;
    end

    handles.ROI = drawfreehand(handles.drawAxes, 'Tag', 'letter', 'Closed', 0, 'Color', [0 0 0], 'LineWidth', 15, 'FaceAlpha', 0);
    
    % Update handles structure
    guidata(hObject, handles);
end


% --- Executes during object creation, after setting all properties.
function imgAxes_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to imgAxes (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: place code in OpeningFcn to populate imgAxes

    set(gca,'XColor', 'none', 'YColor', 'none');
end


% --- Executes during object creation, after setting all properties.
function BTN_NETSIM_DRAWING_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to BTN_NETSIM_DRAWING (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    set(hObject, 'enable', 'inactive');
end
