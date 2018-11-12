
public class Flagger extends Thread{
	public static int curserPos = 0;
	
	public void run() {
		if (curserPos >= 10000) {
			for (int i = 0; i < Main.c; i++) {
				System.out.println(Main.allCons[i]);
			}
		}
		else {
			//System.out.println(curserPos);
		}
	}
}
