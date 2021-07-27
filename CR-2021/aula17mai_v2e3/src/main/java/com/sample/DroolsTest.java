package com.sample;

import org.kie.api.KieServices;
import org.kie.api.runtime.KieContainer;
import org.kie.api.runtime.KieSession;

/**
 * This is a sample class to launch a rule.
 */
public class DroolsTest {

    public static final void main(String[] args) {
        try {
            // load up the knowledge base
	        KieServices ks = KieServices.Factory.get();
    	    KieContainer kContainer = ks.getKieClasspathContainer();
        	KieSession kSession = kContainer.newKieSession("ksession-rules");

            // go !
            Paciente p1 = new Paciente("001", "Ana Melo", 12);
            Paciente p2 = new Paciente("002", "Rui Costa", 17);
            Paciente p3 = new Paciente("003", "Joana Martins", 85);
            Paciente p4 = new Paciente("004", "Pedro Torres", 53);
            Paciente p5 = new Paciente("005", "Ana Gomes", 93);
            
            Sintoma s1 = new Sintoma("001", "febre");
            Sintoma s2 = new Sintoma("001", "manchas");
            Sintoma s3 = new Sintoma("002", "febre");
            Sintoma s4 = new Sintoma("003", "febre");
            Sintoma s5 = new Sintoma("003", "dores");
            Sintoma s6 = new Sintoma("004", "febre");
            Sintoma s7 = new Sintoma("004", "dores");
            Sintoma s8 = new Sintoma("004", "manchas");
            
            kSession.insert(p1);
            kSession.insert(p2);
            kSession.insert(p3);
            kSession.insert(p4);
            kSession.insert(p5);
            
            kSession.insert(s1);
            kSession.insert(s2);
            kSession.insert(s3);
            kSession.insert(s4);
            kSession.insert(s5);
            kSession.insert(s6);
            kSession.insert(s7);
            kSession.insert(s8);
            
            kSession.fireAllRules();
            
        } catch (Throwable t) {
            t.printStackTrace();
        }
    }

}
