class vec3 {
    public:
    vec3();  // constructeur par défaut
    vec3(double x_, double y_, double z_);

    vec3 operator+(const vec3& v) const;
};