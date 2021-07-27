function [] = cbr()

    similarity_threshold = 0.9;
    
    formatSpec = '%f%C%f%f%C%C%f%C%C%C';

    case_library = readtable('TravelCaseBase.csv', ...
        'Delimiter', ',', ...
        'Format', formatSpec);
    
    % New case data
    new_case.holiday_type = 'Active';
    new_case.price = 1500;
    %new_case.number_persons = 4;
    new_case.region = 'Portugal';
    new_case.transportation = 'Car';
    new_case.duration = 10;
    new_case.season = 'July';
    new_case.accommodation = 'ThreeStars';
    
    fprintf('\nStarting retrieve phase...\n\n');
    
    [retrieved_indexes, similarities, new_case] = retrieve(case_library, new_case, similarity_threshold);
    
    retrieved_cases = case_library(retrieved_indexes, :);
    
    retrieved_cases.Similarity = similarities';

    fprintf('\nRetrieve phase completed...\n\n');
    
    disp(retrieved_cases);
    
    if isfield(new_case, 'price') && isfield(new_case, 'number_persons') && isfield(new_case, 'duration')
    
        fprintf('\nStarting reuse phase...\n\n');

        new_price = reuse(retrieved_cases, new_case);

        fprintf('\n\nReuse phase completed...\n');
    else
        new_price = -1;
    end
    
    fprintf('\nStarting revise phase...\n\n');

    [journey, new_case] = revise(retrieved_cases, new_case, new_price);
    
    final_index = find(case_library{:,1} == journey);
    
    fprintf('\nRevise phase completed...\n');
    
    fprintf('\nStarting retain phase...\n\n');

    case_library = retain(case_library, new_case, final_index);
    
    fprintf('\nRetain phase completed...\n\n');
    
    disp(case_library(size(case_library,1), :));

end

