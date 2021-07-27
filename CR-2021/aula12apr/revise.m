function [journey, new_case] = revise(retrieved_cases, new_case, new_price)
    
    retrieved_codes = retrieved_cases{:,1};
    code = str2double('-');
        
    while isnan(code) || fix(code) ~= code || ismember(code, retrieved_codes) == 0
        fprintf('From the retrieved cases, which is the one that better matches your journey?\n');
        code = str2double(input('Journey Code: ','s'));
    end
    
    journey = fix(code);
    
    % REVISE type
    fprintf('\nUpdate your journey holiday_type with a new value? (y/n)\n');
    option = input('Option: ', 's');
    list = {'Active', 'Bathing', 'City', 'Education', 'Language', 'Recreation', 'Skiing', 'Wandering'};

    if option == 'y' || option == 'Y'
        new_type = input('New holiday type: ', 's');
        while sum(ismember(list, new_type)) < 1
            new_type = input('New holiday type: ', 's');
        end
        new_case.holiday_type = new_type;
    end
    
    % REVISE price
    if new_price == -1
        fprintf('\nUpdate your journey price with a new value? (y/n)\n');
        option = input('Option: ', 's');
        
        new_price
    else
        fprintf('\nUpdate your journey price with the new estimated value? (y/n)\n');
        option = input('Option: ', 's');

        if option == 'y' || option == 'Y'
            new_case.price = new_price;
        end
    end
        
    
    % REVISE number_persons
    fprintf('\nUpdate your journey number of people with a new value? (y/n)\n');
    option = input('Option: ', 's');

    if option == 'y' || option == 'Y'
        new_persons = str2double('-');
        while isnan(new_persons)
            new_persons = str2double(input('New number of people: ','s'));
        end
        new_case.number_persons = new_persons;
    end
    
    % REVISE region
    fprintf('\nUpdate your journey region with a new value? (y/n)\n');
    option = input('Option: ', 's');
    if option == 'y' || option == 'Y'
        new_region = input('New holiday type: ', 's');
        new_case.region = new_region;
    end
    
    % REVISE transportation
    fprintf('\nUpdate your journey holiday_type with a new value? (y/n)\n');
    option = input('Option: ', 's');
    list = {'Car', 'Coach', 'Plane', 'Train'};

    if option == 'y' || option == 'Y'
        new_transportation = input('New transportation: ', 's');
        while sum(ismember(list, transportation)) < 1
            new_transportation = input('New transportation: ', 's');
        end
        new_case.transportation = new_transportation;
    end
    
    
    % REVISE duration
    fprintf('\nUpdate your journey duration with a new value? (y/n)\n');
    option = input('Option: ', 's');

    if option == 'y' || option == 'Y'
        new_duration = str2double('-');
        while isnan(new_duration)
            new_duration = str2double(input('New duration: ','s'));
        end
        new_case.duration = new_duration;
    end
    
    % REVISE transportation
    fprintf('\nUpdate your journey season with a new value? (y/n)\n');
    option = input('Option: ', 's');
    list = {'January', 'February', 'March', 'April', 'May', 'June', ...
    	'July', 'August', 'September', 'October', 'November', 'December'};

    if option == 'y' || option == 'Y'
        new_season = input('New season: ', 's');
        while sum(ismember(list, new_season)) < 1
            new_season = input('New season: ', 's');
        end
        new_case.season = new_season;
    end
    
    % REVISE accomodation
    fprintf('\nUpdate your journey accomodation with a new value? (y/n)\n');
    option = input('Option: ', 's');
    list = {'FiveStars', 'FourStars', 'HolidayFlat', 'OneStar', ...
        'ThreeStars', 'TwoStars'};

    if option == 'y' || option == 'Y'
        new_accommodation = input('New accommodation: ', 's');
        while sum(ismember(list, new_accomodation)) < 1
            new_accommodation = input('New accommodation: ', 's');
        end
        new_case.accommodation = new_accommodation;
    end
end

