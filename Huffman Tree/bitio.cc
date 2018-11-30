#include "bitio.hh"
#include <cassert>

BitIO::BitIO(std::ostream* os, std::istream* is)
{
    assert(!(os and is) or (os or is));
    os_ = os;
    is_ = is;
}

BitIO::~BitIO()
{
    if(os_ and bitAt_ > 0)
    {
        *os_ << writeByte_;
    }
}

void BitIO::output_bit(bool bit)
{
    //check for output stream
    if(!os_)
    {
        assert(false);
    }
    //set a bit
    if(bit)
    {
        writeByte_ |= (1 << (7 - bitAt_));
    }
    bitAt_++;
    //push and reset stuff after filling up a byte
    if(bitAt_ == 8)
    {
        *os_ << writeByte_;
        bitAt_ = 0;
        writeByte_ = 0x0;
    }
    return;
}

bool BitIO::input_bit()
{
    if(!is_)
    {
        assert(false);
    }
    if(bitAt_ == 0)
    {
        *is_ >> storedByte_;
    }
    bool relevBit = storedByte_ & (0x1 << (7 - bitAt_));
    bitAt_++;
    if(bitAt_ == 8)
    {
        bitAt_ = 0;
    }
    return relevBit;
}
