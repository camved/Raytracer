class vec3 {
    public:
    vec3();  // constructeur par défaut

    vec3(double x_, double y_, double z_);

    vec3 operator+(const vec3& v) const; //addition
    vec3 operator-(const vec3& v) const; //soustraction
    vec3 operator*(double t) const; //multiplication
    double lenght() const; //norme du vecteur
};