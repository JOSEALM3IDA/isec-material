package jogo.utils;

import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

public class Utils {

    private Utils() {}

    private static final Random random = new Random();

    public static int getNumeroRandom(int bound) { return random.nextInt(bound); }

    public static double round(double value, int places) {
        if (places < 0) throw new IllegalArgumentException();

        BigDecimal bd = new BigDecimal(Double.toString(value));
        bd = bd.setScale(places, RoundingMode.HALF_UP);
        return bd.doubleValue();
    }

    public static List<String> lerLinhasParaLista(String nomeFicheiro) {
        List<String> linhas = new LinkedList<>();

        File fich = new File(nomeFicheiro);

        Scanner sc;
        try { sc = new Scanner(fich); } catch (FileNotFoundException fnfe) { return linhas; }

        while (sc.hasNextLine()) linhas.add(sc.nextLine());

        sc.close();

        return linhas;
    }

    public static List<String> getFicheirosNoDiretorio(String diretorio) {
        File dir = new File(diretorio);

        if (dir.mkdirs()) return Collections.emptyList();

        return Arrays.asList(Objects.requireNonNull(dir.list()));
    }

    public static boolean gravarObjeto(String path, Object objeto) {
        File f = new File(path);
        if (f.exists()) return false;

        f.getParentFile().mkdirs();


        try (
                FileOutputStream fos = new FileOutputStream(f);
                ObjectOutputStream oos = new ObjectOutputStream(fos)
                ) {
            oos.writeObject(objeto);
        } catch (IOException ioe) { ioe.printStackTrace(); return false; }

        return true;
    }

    public static <T> T lerObjeto(String path, Class<T> tClass) {

        Object obj;
        try (FileInputStream fis = new FileInputStream(path); ObjectInputStream ois = new ObjectInputStream(fis)) {
            obj = ois.readObject();
        } catch (IOException | ClassNotFoundException ex) { ex.printStackTrace(); return null; }

        if (obj == null) return null;

        return tClass.cast(obj);
    }

}
