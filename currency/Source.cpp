#include <iostream>
#include <string>
#include <sstream>
#include <curl/curl.h>
#include <json/json.h>

class CurrencyConverter {
private:
    std::string apiKey;

    // Function to handle HTTP response
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);

    // Function to get exchange rate
    double getExchangeRate(const std::string& from, const std::string& to);

public:
    CurrencyConverter(const std::string& apiKey);

    // Function to convert currency
    double convertCurrency(double amount, const std::string& from, const std::string& to);
};

CurrencyConverter::CurrencyConverter(const std::string& apiKey) : apiKey(apiKey) {}

size_t CurrencyConverter::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

double CurrencyConverter::getExchangeRate(const std::string& from, const std::string& to) {
    CURL* curl = curl_easy_init();
    std::string url = "https://api.exchangerate-api.com/v4/latest/" + from + "?apiKey=" + apiKey;

    if (curl) {
        std::string response;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "Failed to retrieve exchange rates: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
            return -1.0;
        }

        curl_easy_cleanup(curl);

        Json::Reader reader;
        Json::Value root; // Declare root here

        if (!reader.parse(response, root)) {
            std::cerr << "Failed to parse JSON: " << reader.getFormattedErrorMessages() << std::endl;
            return -1.0;
        }

        double rate = root["rates"][to].asDouble();
        return rate;
    }

    return -1.0;
}

double CurrencyConverter::convertCurrency(double amount, const std::string& from, const std::string& to) {
    double exchangeRate = getExchangeRate(from, to);

    if (exchangeRate == -1.0) {
        std::cerr << "Failed to get exchange rate. Conversion aborted." << std::endl;
        return -1.0;
    }

    return amount * exchangeRate;
}

int main() {
    // Replace "YOUR_API_KEY" with your ExchangeRate-API key
    CurrencyConverter converter("aa6dc93ea0b6412e9af0a45758b6df3e");

    double amount;
    std::string fromCurrency, toCurrency;

    std::cout << "Enter the amount: ";
    std::cin >> amount;

    std::cout << "Enter the currency to convert from: ";
    std::cin >> fromCurrency;

    std::cout << "Enter the currency to convert to: ";
    std::cin >> toCurrency;

    double result = converter.convertCurrency(amount, fromCurrency, toCurrency);

    if (result != -1.0) {
        std::cout << amount << " " << fromCurrency << " is equal to " << result << " " << toCurrency << std::endl;
    }

    return 0;
}
