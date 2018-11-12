
/*
* Each consumer represents an entity that reads sales records and computes sales statistics locally.
*/
public class Consumer extends Thread{
	private int ID;
	private double[] storeSales, monthSales;
	private double totalSales;
	
	public Consumer(int ID) {
		this.ID = ID;
		this.storeSales = new double[Main.p - 1];
		this.monthSales = new double[12];
		this.totalSales = 0.0;
	}
	
	public void run() {
		do {
			BufferItems temp = Main.buffer.get(3);
			this.storeSales[temp.getStoreID() - 1] += temp.getSale();
			this.monthSales[temp.getMonth()] += temp.getSale();
			this.totalSales += temp.getSale();
			Flagger.curserPos += 1;
		} while (Flagger.curserPos < 10000);
	}
	
	public String toString() {
		String msg = "Store Sales: \n";
		for (int i = 0; i < Main.p - 1; i++) {
			msg += "\tStore #" + (i+1) + ": " + this.storeSales[i] + "\n";
		}
		return msg;
	}
	
}
