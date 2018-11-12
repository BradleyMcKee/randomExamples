public class BufferItems{
	private String salesDate;
	private int storeID, registerNum;
	private double salesAmount;
	
	public BufferItems(String d, int ID, int rn, double s) {
		this.salesDate = d;
		this.storeID = ID;
		this.registerNum = rn;
		this.salesAmount = s;
	}
	
	//TODO: Add mutators as needed
	
	public int getStoreID() {
		return this.storeID;
	}
	
	public double getSale() {
		return this.salesAmount;
	}
	
	public int getMonth() {
		String[] allNums = this.salesDate.split("/");
		return Integer.parseInt(allNums[1]);
	}
	
	
	public String getSalesDate() {
		return this.salesDate;
	}
	
	public String toString() {
		return "Sales Date: " + this.salesDate + "\nStore ID: " + this.storeID + "\nRegister Number: " + this.registerNum + "\nSale Amount: " + this.salesAmount + "\n";
	}

}
