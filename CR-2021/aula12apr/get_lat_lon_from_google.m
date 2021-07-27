function [lat, lon] = get_lat_lon_from_google(name)
    
    baseUrl = sprintf(['https://maps.googleapis.com/maps/api/geocode/json?' ...
                        'key=AIzaSyDdHuvaZE2fHOpyiHJgzMEETx7pn74JMA0&' ...
                        'address=%s&sensor=true'], name);

    finalUrl = strrep(baseUrl, ' ', '%20');
    
    json = urlread(finalUrl);
    
    jsonData = parse_json(json);
    
    if numel(jsonData{1}.results) > 0
        lat = jsonData{1}.results{1}.geometry.location.lat;
        lon = jsonData{1}.results{1}.geometry.location.lng;       
    else
        lat = 0;
        lon = 0;
    end
end

