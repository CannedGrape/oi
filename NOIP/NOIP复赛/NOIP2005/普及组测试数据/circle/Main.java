import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	static BigInteger DIV = null;
	static BigInteger N = null;
	
	static boolean isequal(BigInteger zhishu) {
		BigInteger temp = N.modPow(
				zhishu.add(BigInteger.ONE), DIV);
//		System.out.println(temp);
		return temp.equals(N);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		
		N = new BigInteger(scanner.next());
		int K = scanner.nextInt();
		
		DIV = new BigInteger("10").pow(K);
		
		N = N.remainder(DIV);
		
//		System.out.println(N)
		
		BigInteger result = DIV.multiply(new BigInteger("4"));
	
		if (!isequal(result)) {
			System.out.println(-1);
			return;
		}
		
		while(true) {
//			System.out.println(result);
			BigInteger[] temp = result.divideAndRemainder(new BigInteger("5"));
			if (temp[1].equals(BigInteger.ZERO) && 
					isequal(temp[0])) {
				result = temp[0];
				continue;
			}
			
			temp = result.divideAndRemainder(new BigInteger("2"));
			if (temp[1].equals(BigInteger.ZERO) && 
					isequal(temp[0])) {
				result = temp[0];
				continue;
			}
			
			System.out.println(result);
			break;
		}
	}

}
