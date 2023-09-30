/*



*/

#ifndef  HELPERS_H
#define  HELPERS_H

class ScopedTimer {
public:
using ClockType = std::chrono::steady_clock;
ScopedTimer(const char* func)
: function_name_{func}, start_{ClockType::now()} {}
ScopedTimer(const ScopedTimer&) = delete;
ScopedTimer(ScopedTimer&&) = delete;
auto operator=(const ScopedTimer&) -> ScopedTimer& = delete;
auto operator=(ScopedTimer&&) -> ScopedTimer& = delete;
~ScopedTimer() {
using namespace std::chrono;
auto stop = ClockType::now();
auto duration = (stop - start_);
auto ms = std::chrono::duration<double, std::milli>(duration).count();
std::cout << function_name_ << " ms " << ms  << '\n';
}
private:
const char* function_name_{};
const ClockType::time_point start_{};
};

std::vector<std::string> readCSV(const std::string& filename)
{
  //ScopedTimer timer{"readCSV"};

	std::vector<std::string> words;
	std::ifstream file(filename);
	std::string line;

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string word;

		while (std::getline(ss, word, ' '))
		{
			words.push_back(word);
		}
	}

	return words;
}



void flushVectorToFile(const std::vector<int>& vec, const std::string& filename)
{
    // ScopedTimer timer{"flushVectorToFile"};
	std::ofstream file(filename);

	if (file.is_open())
	{
		for (const int& num : vec)
		{
			file << num << " ";
		}

		file.close();
		std::cout << "Data flushed to file successfully." << std::endl;
	}
	else
	{
		std::cerr << "Unable to open the file." << std::endl;
	}
}


void flushVectorToFile(const std::vector<double>& vec, const std::string& filename)
{
 	//ScopedTimer timer{"flushVectorToFileDouble"};

	std::ofstream file(filename);

	if (file.is_open())
	{
		for (const double& num : vec)
		{
			file << std::setprecision(7) << std::fixed << num << "\n";
		}

		file.close();
		std::cout << "Data flushed to " << filename << std::endl;
	}
	else
	{
		std::cerr << "Unable to open the file." << std::endl;
	}
}

void flushVectorToFile(const std::vector<std::string> vec, const std::string& filename)
{
	//ScopedTimer timer{"flushVectorToFileString"};
	std::ofstream file(filename);

	if (file.is_open())
	{
		for (const auto& string : vec)
		{
			file << string << "\n";
		}

		file.close();
		std::cout << "Please see " << filename << "." << std::endl;
	}
	else
	{
		std::cerr << "Unable to open the file." << std::endl;
	}
}


void deleteZeros(std::vector<double>& nums)
{
	//ScopedTimer timer{"deleteZeros"};
	nums.erase(std::remove(nums.begin(), nums.end(), 0.000000), nums.end());
}




void outputBatchCollector(const std::vector<std::vector<double>>& vec, const std::string& fileName)
{
   //ScopedTimer timer{"outputBatchCollector"};
    std::ofstream outFile(fileName);

    if (!outFile.is_open())
    {
        std::cerr << "Failed to open file " << fileName << std::endl;
        return;
    }

    for (const auto& innerVec : vec)
    {
        outFile << "{";
        for (const double& val : innerVec)
        {
            outFile  << std::fixed << std::setprecision(6) << val << ", ";
        }

        outFile << "}," << std::endl;
    }

    outFile.close();
}




std::unordered_map<char, int> countLetters(std::string inputFilename)
{
   // ScopedTimer timer{"countLettersCi"};
	//data variables
	std::unordered_map<char, int> letters;

	//open the file
	std::ifstream file_in;
	file_in.open(inputFilename);
	if (!file_in.is_open())
	{
		std::cerr << "Failed to open file." << std::endl;

	}

	//do the dew
	char c;
	int count {0};
	while (file_in >> c)
	{
		count++;
		if (std::isalpha(c))
		{
			letters[std::toupper(c)]++;
		}
	}

	file_in.close();

	return letters;
}


int countPunctuations(const std::vector<std::string>& strings) {
	// ScopedTimer timer{"countPunctuations"};
    
    int count = 0;
    std::string punctuations = ".,;:!?";

    for (const std::string& str : strings) {
        for (const char& c : str) {
            if (std::find(punctuations.begin(), punctuations.end(), c) != punctuations.end()) {
                count++;
            }
        }
    }

    return count;
}
//diff
int heuristicCount(const std::vector<std::string>& strings, std::string& magic) {
    //ScopedTimer timer{"heuristicCountString"};
    int count {0};
    
    for (const std::string& word : strings) {
        if (word == magic ) {
            count++;
        }
    }
    return count;
}

int heuristicCount(const std::vector<double>& strings, double& magicNumber) {
      // ScopedTimer timer{"heuristicCountDouble"};
    int count = 0;
    for (const double& number : strings) {
        if (number == magicNumber ) {
            count++;
        }
    }
    return count;
}

int count_vowels(std::vector<std::string> strings, char magic) {
	// ScopedTimer timer{"count_vowels"};
  
  int count {0};
  for (const std::string& word : strings) {
    for (const char& c : word) {
      if (std::tolower(c) == magic) {
      
      }
    }
  }
  return count;
}


int uppercaseSearch(const std::vector<std::string>& words) {
	// ScopedTimer timer{"uppercaseSearch"};
	
	int count {0};  
	for (const std::string& word : words) {
        if (word.size() >= 3 && std::isupper(word[2])) {
		//std::cout << word << std::endl;            
		count++;
        }
    }
    return count;
}

int mcdonaldsSearch(const std::vector<std::string>& words) {
	// ScopedTimer timer{"mcds"};
	
	int count {0};  
	for (const std::string& word : words) {
        if (word.size() >= 2 && std::isupper(word[1])) {
		//std::cout << word << std::endl;            
		count++;
        }
    }
    return count;
}

int countSentences(const std::string& filename) {
	// ScopedTimer timer{"countSentences"};
   
    int totalSentences {0};
 
    
    std::ifstream file(filename);
    std::string sentence;

    if (file.is_open()) {
        while (std::getline(file, sentence)) {
            std::istringstream iss(sentence);
            std::string word;

            while (iss >> word) {
                if (word.back() == '!' || word.back() == '?' || word.back() == '.' || word.back() == '"') { 
                    totalSentences++;
                }
              
            }
        }

        file.close();
    }

    if (totalSentences == 0) {
        return 0;
    } 
    else {
        return totalSentences;
    }
}

int getLargestSentenceSize(std::string filename) {
	// ScopedTimer timer{"getLargestSentenceSize"};
    
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        return -1;
    }

    std::string line;
    int max_sentence_size = 0;

    while (std::getline(file, line)) {
        // Split line into sentences
        std::replace(line.begin(), line.end(), '.', ' ');
        std::replace(line.begin(), line.end(), '!', ' ');
        std::replace(line.begin(), line.end(), '?', ' ');

        // Split sentences into words
        std::istringstream iss(line);
        std::string word;
        int sentence_size = 0;

        while (iss >> word) {
            sentence_size++;
        }

        if (sentence_size >= max_sentence_size) {
            max_sentence_size = sentence_size;
        }
    }

    file.close();
    return max_sentence_size;
}

// Robert Jenkins' 96 bit Mix Function
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

std::string generateFileName(){
//ScopedTimer timer{"generateFileName"};	

unsigned long seed = mix(clock(), time(NULL), getpid());
	
	std::string fileName;
	int length = 11;

	//initialize random seed
	std::srand(seed);

	//generate random characters
	for(int i = 0; i < length; i++)
	{
		
		fileName += std::rand() % 26 + 'a';
	}

	
	return fileName;
}

void cleanItUp(const std::string& filename) {
 //ScopedTimer timer{"cleanItUp"};

    std::ifstream infile(filename);
    
    std::ofstream outfile("temp.txt");
    std::string line;
   
    while (std::getline(infile, line)) {
        for (unsigned int i = 0; i < line.length(); i++) {
            outfile << line[i];
            if (line[i] == '.') {
                outfile << std::endl;
            }
        }
        outfile << std::endl;
    }
    
    
    infile.close();

    outfile.close();
    
    std::rename("temp.txt", filename.c_str());
    
}

bool compareVectors(const std::vector<double>& v1, const std::vector<double>& v2) {
 
    return v1.size() < v2.size();
  
}

void sortBatchCollector(std::vector<std::vector<double>>& vectors) {
      // ScopedTimer timer{"sortBatchCollector"};
    
    std::sort(vectors.begin(), vectors.end(), compareVectors);
}



int mtRand(double upperbound) {
 //ScopedTimer timer{"mtrand"};
    
   
    if(upperbound != 0){
    // Create a Mersenne Twister random number generator
    std::mt19937_64 mt_rand(std::random_device{}());

    // Define a uniform distribution from 0 to 0.5
    std::uniform_real_distribution<double> dist(0, upperbound-1);

    // Generate a random double using the distribution and return it
    return dist(mt_rand);
    }
    else{
    std::cout << " You didnt say the magic word!" << std::endl;
    return 0;
    }
}

int detectorMul(const std::vector<double>& sum, const double& threshold) {
    int count {0};
    for (const double& val : sum) {
        if (val > threshold) {
            count++;
        }
    }
    return count;
}




#endif //helpers.h
