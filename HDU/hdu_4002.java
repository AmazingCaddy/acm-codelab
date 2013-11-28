import java.math.*;
import java.util.*;

public class Main {
    public static void main(String [] args) {
        Scanner cin = new Scanner(System.in);
        String [] pLst = {"2","3","5","7","11","13","17","19","23","29","31","37","41","43","47","53","59","61","67","71",
			"73","79","83","89","97","101","103","107","109","113","127","131","137","139","149","151","157","163","167","173",
			"179","181","191","193","197","199","211","223","227","229","233","239","241","251","257","263","269","271","277","281"};

        List <BigInteger> table = new ArrayList <BigInteger> ();
        table.add(BigInteger.ONE);
        
        int tblCases = pLst.length;
        
        for (int i = 0; i < tblCases; i++)
            table.add(table.get(i).multiply(new BigInteger(pLst[i])));
        
        int testCases = cin.nextInt();
        while (--testCases >= 0) {
            String r = cin.next();
            BigInteger num = new BigInteger(r);
            
            for (int j = tblCases; j > 0 ; j--) {
                if (table.get(j).compareTo(num) <= 0) {
                    System.out.println(table.get(j));
                    break;
                }
            }
        }        
    }
}