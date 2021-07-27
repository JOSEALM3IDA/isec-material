package pt.isec.jalmeida.f3e4;

import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

// Dictionary to translate from PORTUGUESE to ACTIVELANGUAGE
public class Dictionary {
    private String activeLanguage;
    private Map<String, Map<String, String>> dict;

    public Dictionary() {
        this.activeLanguage = "ENGLISH";
        this.dict = new HashMap<>();
    }

    public void add(String language, String concept, String translation) {
        if (!this.dict.containsKey(language.toUpperCase()))
            this.dict.put(language.toUpperCase(), new HashMap<>());

        this.dict.get(language.toUpperCase()).put(concept.toUpperCase(), translation.toUpperCase());
    }

    public boolean defineLang(String newLang) {
        if (!this.dict.containsKey(newLang.toUpperCase()))
            return false;

        this.activeLanguage = newLang.toUpperCase();
        return true;
    }

    public String get(String concept) {
        String transl = dict.get(activeLanguage).get(concept.toUpperCase());
        if (transl == null)
            return "-";

        return transl;
    }
}
