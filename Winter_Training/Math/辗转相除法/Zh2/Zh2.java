/*
加练题：Astronomy_POJ 3101
	最小公倍数+高精度。 
*/
import java.math.*;

import java.util.*;

public class Zh2 {

    public static void main(String[ ]  args)
    {
        Scanner cin = new Scanner(System.in);

        int n  ,cnt;

        int [ ] t  =new  int[1100];
        int [ ]s = new int [1100];

        BigInteger a,b,g,mo = null,de = null;

        while(cin.hasNext())
        {
            cnt = 1;

            n = cin.nextInt();

            for(int i = 0;i<n;i++) t[i] = cin.nextInt();

            Arrays.sort(t,0,n);

            s[0]  =t[0];

            for(int i = 1;i<n;i++)
            {               
                if(t[i]!=t[i-1])
                {
                    s[cnt++] = t[i];
                }
            }

            for(int i = 1;i<cnt;i++)
            {
                a = BigInteger.valueOf(s[i]*s[0]);

                b = BigInteger.valueOf((s[i]-s[0])*2);

                g =  a.gcd(b);

                if(i == 1)
                {
                    mo = a.divide(g);

                    de = b.divide(g); 
                }
                else
                {
                    a  = a.divide(g);

                    b = b.divide(g);

                    mo = mo.multiply(a).divide(mo.gcd(a));

                    de = de.gcd(b);
                }
            }

            System.out.println(mo+" "+de);
        }

        cin.close();
    }
}
