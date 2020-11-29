using namespace std;

class PaperRepository
{
public:
    PaperRepository();
    ~PaperRepository();

    void addPaper(const string& paperTitle, const string& journalTitle, const int publicationYear);
    void removePaper(const string& paperTitle);
    void addCoauthor(const string& paperTitle, const string& coauthorFirstName, const string& coauthorLastName,
                     const string& coauthorInstitution);
    void removeCoauthor(const string& coauthorFirstName, const string& coauthorLastName);
    void showAllPapers();
    void showCoauthor(const string& coauthorFirstName, const string& coauthorLastName);
    void showJournal(const string& journalTitle);

private:
    struct Node
    {
        string dataPaperTitle;
        string dataJournalTitle;
        int dataPublicationYear;
        Node* next;
        Node* prev;
    };

    Node* head;

};

