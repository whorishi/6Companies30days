/*
You are given a stream of records about a particular stock. Each record contains a timestamp and the corresponding price of the stock at that timestamp.

Unfortunately due to the volatile nature of the stock market, the records do not come in order. Even worse, some records may be incorrect. Another record with the same timestamp may appear later in the stream correcting the price of the previous wrong record.

Design an algorithm that:

Updates the price of the stock at a particular timestamp, correcting the price from any previous records at the timestamp.
Finds the latest price of the stock based on the current records. The latest price is the price at the latest timestamp recorded.
Finds the maximum price the stock has been based on the current records.
Finds the minimum price the stock has been based on the current records.
Implement the StockPrice class:

* StockPrice() Initializes the object with no price records.
* void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
* int current() Returns the latest price of the stock.
* int maximum() Returns the maximum price of the stock.
* int minimum() Returns the minimum price of the stock.
*/

class StockPrice {
public:
    unordered_map<int,int>stock;
    int maxTimestamp=0;
    multiset<int>prices;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(stock.find(timestamp)!=stock.end())
        {
            prices.erase(prices.find(stock[timestamp]));
        }
        stock[timestamp]=price;
        prices.insert(price);
        maxTimestamp = max(maxTimestamp,timestamp);
    }
    
    int current() {
        return stock[maxTimestamp];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */