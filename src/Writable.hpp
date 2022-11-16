#include <iosfwd>

class Writable {
public:
	virtual void write(std::ostream&) const = 0;
};

class Readable {
public:
	virtual void read(std::istream&) = 0;
};

class Drawable {
public:
	virtual void draw() const = 0;
};

class Character : public Writable, public Readable, public Drawable {

};
