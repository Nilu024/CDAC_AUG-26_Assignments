public class EquilateralTriangle  implements RegularPolygon {

	private double sideLength;

	public EquilateralTriangle(double sideLength) {
		this.sideLength = sideLength;
	}
	
	@Override
	public int getNumSides() {
		return 3;
	}

	@Override
	public double getSideLength() {
		return sideLength;
	}
	
}
