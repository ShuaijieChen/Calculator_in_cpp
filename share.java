import java.util.Scanner;
public class share {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        //n indicating the total number of transactions in the input sequence
        int length = (2n-2);
        int[] arrayShare = new int[];
        //Use arrayShare to store share prices and purchase quantities
        for(int i=0;i<n;i++){
            arrayShare[i]=in.nextInt();
        }
        for(int j=0;j<(2n-2);j++){
            System.out.println(arrayShare[j]);
        }
    }
}