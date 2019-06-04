class sortedArr {
    public:
        sortedArr();
        void removeAll();
        bool full() const;
        int getLength();
        void insert(int val);
        void remove(int val);
        void displayArr();
        void inList(int val);
    private:
        int length;
        //only for the array section
        int values[100];
};