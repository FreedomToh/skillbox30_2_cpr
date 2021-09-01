#include <iostream>
#include <string>
#include <cpr/cpr.h>

class Requests {
private:
    std::string url;
    cpr::Response r;
public:
    Requests(const std::string &val) {
        if (val.length() == 0) return;

        this->url = val;
    }

    bool getHtml() {
        if (this->url.length() == 0) return false;

        std::string tmp_url = this->url+"/html";
        r = cpr::Get(cpr::Url(tmp_url), cpr::Header({{"accept", "text/html"}}));

        if (r.status_code != 200) {
            this->getErrors();
            return false;
        }

        return true;
    }

    void getHtmlElement(std::string_view tagA, std::string_view tagB) {
        if (r.text.empty()) return;

        std::string h1;

        int start = r.text.find(tagA) + tagA.length();
        int stop = r.text.find(tagB, start);
        h1 = r.text.substr(start, stop - start);
        std::cout << h1 << std::endl;
    }

    void getErrors() {
        if (r.status_code == 200) return;

        if (r.status_code == 0) {
            std::cerr << r.error.message << std::endl;
        } else if (r.status_code == 400) {
            std::cerr << "Error [" << r.status_code << "] making request" << std::endl;
        }
    }


};

int main() {
    std::cout << "CPR_30_2" << std::endl;

    Requests *r = new Requests("http://httpbin.org/");
    r->getHtml();

    std::cout << "Header <h1>: ";
    r->getHtmlElement("<h1>", "</h1>");

    delete r;
    return 0;
}
