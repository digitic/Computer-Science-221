#include "huffman.hh"

Huffman::Huffman()
{
    for(int i = 0; i < ALPHABET_SIZE - 1; i++)
    {
        freq_table_[i] = 0;
    }
    freq_table_[ALPHABET_SIZE - 1] = 1;
}

Huffman::~Huffman()
{
}

Huffman::bits_t Huffman::encode(int symbol)
{
    make_huffman_tree();
    bits_t bitsSequence;

    auto holdPath = huffTree_->path_to(symbol);
    freq_table_[symbol]++;

    for(auto c: holdPath)
    {
        if(c == HTree::Direction::LEFT)
        {
            bitsSequence.push_back(0);
        }
        if(c == HTree::Direction::RIGHT)
        {
            bitsSequence.push_back(1);
        }
    }
    return bitsSequence;
}

int Huffman::decode(bool bit)
{
    if(huffTree_ == nullptr)
    {
        make_huffman_tree();
    }
    int thisNodeSymbol;

    if(!bit)
    {
        huffTree_ = huffTree_->get_child(HTree::Direction::LEFT);
        thisNodeSymbol = huffTree_->get_key();
    }
    else
    {
        huffTree_ = huffTree_->get_child(HTree::Direction::RIGHT);
        thisNodeSymbol = huffTree_->get_key();
    }
    if(thisNodeSymbol >= 0)
    {
        freq_table_[thisNodeSymbol]++;
        huffTree_ = nullptr;
        return thisNodeSymbol;
    }
    return -1;
}

void Huffman::make_huffman_tree()
{
    for(int i = 0; i < ALPHABET_SIZE - 1; i++)
    {
        forest_.add_tree(HTree::tree_ptr_t(new HTree(i, freq_table_[i])));
    }
    forest_.add_tree(HTree::tree_ptr_t(new HTree(HEOF, 1)));

    while(forest_.size() > 1)
    {
        auto lowestFreq1 = forest_.pop_top();
        auto lowestFreq2 = forest_.pop_top();
        forest_.add_tree(HTree::tree_ptr_t(new HTree(-1, (lowestFreq1->get_value() + lowestFreq2->get_value()), lowestFreq1, lowestFreq2)));
    }
    huffTree_ = forest_.pop_top();
}