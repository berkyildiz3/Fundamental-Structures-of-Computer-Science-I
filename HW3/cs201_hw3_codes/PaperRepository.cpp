#include <iostream>
#include <string>
#include "PaperRepository.h"
#include <cstddef>


PaperRepository::PaperRepository():head(NULL) {};
PaperRepository::~PaperRepository() {};

void PaperRepository::addPaper(const string& paperTitle, const string& journalTitle, const int publicationYear)
{
    int count = 0;
    Node* iter = head;

    if(head == NULL)
    {
        head = new Node;
        head->dataPaperTitle = paperTitle;
        head->dataJournalTitle = journalTitle;
        head->dataPublicationYear = publicationYear;
        head->next = head;
        head->prev = head;
        cout << "INFO: Paper " << paperTitle << " has been added." << endl;
    }
    else
    {
        if(iter->next == head)
        {
            if(iter->dataPaperTitle == paperTitle)
            {
                count++;
            }

        }
        while(iter->next != head)
        {
            if(iter->dataPaperTitle == paperTitle || iter->next->dataPaperTitle == paperTitle)
            {
                count++;
            }
            iter = iter->next;
        }
        if(count == 0)
        {
            Node *temp = head;
            Node *temp2 = new Node;
            temp2->dataPaperTitle = paperTitle;
            temp2->dataJournalTitle = journalTitle;
            temp2->dataPublicationYear = publicationYear;
            temp2->next = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = temp2;
            temp2->prev = temp;
            cout << "INFO: Paper " << paperTitle << " has been added." << endl;
        }
        else
        {
            cout << "ERROR: Paper " << paperTitle << " already exists." << endl;
        }
    }
}

void PaperRepository::removePaper(const string& paperTitle)
{
    int count = 0;
    Node* iter = head;
    if(head == NULL)
    {
        cout << "Repository is empty!" << endl;
    }
    else if (iter->next == head)
    {
        if(head->dataPaperTitle == paperTitle)
        {
            cout << "INFO: Paper " << paperTitle << " has been deleted." << endl;
            head = NULL;
        }
    }
    else
    {
        while(iter->next != head)
        {
            if(iter->dataPaperTitle == paperTitle || iter->next->dataPaperTitle == paperTitle)
            {
                count++;
                if(head->dataPaperTitle == paperTitle)
                {
                    Node* temp = head;
                    while(temp->next != head)
                    {
                        temp = temp->next;
                    }
                    head = head->next;
                    temp->next = head;
                    head->prev = temp;
                    cout << "INFO: Paper " << paperTitle << " has been deleted." << endl;
                }
                else
                {
                    Node* temp = head;
                    while(temp->next->dataPaperTitle != paperTitle)
                    {
                        temp = temp->next;
                    }

                    Node* temp1 = temp->next;
                    temp->next->next->prev = temp;
                    temp->next = temp->next->next;
                    delete temp1;
                    cout << "INFO: Paper " << paperTitle << " has been deleted." << endl;
                }
            }
            iter = iter->next;
        }
        if(count == 0)
        {
            cout << "ERROR: Paper " << paperTitle << " does not exist." << endl;
        }
    }
}

void PaperRepository::showAllPapers()
{
    if(head == NULL)
    {
        cout << "--- none ---" << endl;
    }
    else
    {
        Node* temp = head;
        do
        {
            cout << temp->dataPaperTitle << ", " << temp->dataJournalTitle << ", " << temp->dataPublicationYear << endl;
            temp = temp->next;
        }
        while(temp != head);
    }
}




