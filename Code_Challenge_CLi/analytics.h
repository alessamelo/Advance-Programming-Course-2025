#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <string>
#include <vector>
#include <unordered_map>

struct Transaction {
    std::string invoiceNo;
    std::string stockCode;
    std::string description;
    int quantity;
    double unitPrice;
    std::string customerID;
    std::string country;
};

class Analytics {
public:
    Analytics(const std::string& filename);
    void loadData(bool onlyUK = false);
    std::unordered_map<std::string, int> getTransactionsByCountry() const;
    double getTotalAmount() const;
    const std::vector<Transaction>& getTransactions() const;

private:
    std::string filename;
    std::vector<Transaction> transactions;
    mutable std::unordered_map<std::string, int> countryCounts;
    mutable double totalAmount;
    mutable bool isAnalyzed;

    void analyzeData() const;
    void updateProgress(float progress, const std::string& message) const;
};

#endif