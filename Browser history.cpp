#include <iostream>
#include <string>
#include <stack>

typedef std::stack<std::string> StackOfStrings;

std::string readURL() {
    std::string URL;
    std::cin >> URL;
    return URL;
}

StackOfStrings PreviousURLs(const std::string& URL, StackOfStrings& history) {
    history.push(URL);
    std::cout << "Current URL: " << URL << std::endl;

    return history;
}

void executeBackPageButton(StackOfStrings& history) {
    if (history.empty())
    {
        std::cout << "You are at homepage." << std::endl;
    }
    else
    {
        history.pop();
        if (history.empty())
        {
            std::cout << "You are at homepage." << std::endl;
        }
        else
        {
            std::cout <<  "Current URL: " << history.top() << std::endl;
            history.pop();
        }
       
    }
    
}



int main()
{
    std::string URL = readURL();

    StackOfStrings history;
    StackOfStrings forwardURLs;

    while (URL != "end")
    {
       
        if (URL == "/back")
        {
            executeBackPageButton(history);
        }
        else
        {
            PreviousURLs(URL, history);
        }
        URL = readURL();
    }
    


    return 0;
}
