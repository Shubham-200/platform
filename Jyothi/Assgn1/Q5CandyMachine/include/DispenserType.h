class DispenserType
{
	private:
		int noOfItem;
		int cost;

	public:
		DispenserType(){
			noOfItem = 50;
			cost = 50;
		}

		DispenserType(int item, int c){
			noOfItem = item;
			cost = c;
		}

		int getNoOfItems(){
			return noOfItem;
		}

		int getCost(){
			return cost;
		}

		void makeSale(void){
			noOfItem -= 1;
		}
};
