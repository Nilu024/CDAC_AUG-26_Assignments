public interface RegularPolygon {

	int getNumSides();
	
	double getSideLength();
	
	static int totalSides(RegularPolygon[] polygons) {
		int total = 0;
		for (RegularPolygon regularPolygons : polygons) {
			total += regularPolygons.getNumSides();
		}
		
		return total;
	}

	default double getPerimeter() {
		return getNumSides() * getSideLength();
	}
	
	default double getInteriorAngle() {
		return (getNumSides() - 2 ) * Math.PI / getNumSides();
	}
	
	
}
