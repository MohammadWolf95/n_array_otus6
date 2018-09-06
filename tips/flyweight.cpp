using namespace std;

class Gazillion
{
  public:
    Gazillion(int value_one)
    {
        m_value_one = value_one;
        cout << "ctor: " << m_value_one << '\n';
    }
    ~Gazillion()
    {
        cout << m_value_one << ' ';
    }
    void report(int value_two)
    {
        cout << m_value_one << value_two << ' ';
    }
  private:
    int m_value_one;
};

class Factory
{
  public:
    static Gazillion *get_fly(int in)
    {
        if (s_pool.find(in)==s_pool.end())
          s_pool.insert(make_pair(in, new Gazillion(in)));
        return s_pool.find(in)->second;
    }
    static void clean_up()
    {
        cout << "dtors: ";
        for (int i = 0; i < X; ++i)
          if (s_pool.find(i)->second){
              auto it = s_pool.find(i);
            delete s_pool.find(i)->second;
              s_pool.erase(it);
          }
        cout << '\n';
    }
    static int X, Y;
  private:
    static map<int, Gazillion*> s_pool;
};


int Factory::X = 6, Factory::Y = 10;
map<int, Gazillion*> Factory::s_pool;

int main(int argc, char**argv){
	for (int i = 0; i < Factory::X; ++i)
      {
        for (int j = 0; j < Factory::Y; ++j)
          Factory::get_fly(i)->report(j);
        cout << '\n';
      }
      Factory::clean_up();
} 
