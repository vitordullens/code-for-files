using namespace std;

namespace HE{
    class Element{
        unsigned int GroupNumber, ElNumber;
        string VR;
        string Name;
        char* value;
    public:
        // Costructor of empty element
        Element(){
            GroupNumber = 0;
            ElNumber = 0;
            VR = "";
            Name = "";
        }
        // Constructor of known element
        Element(unsigned int g,unsigned int e, string vr = "", string name = ""){
            GroupNumber = g;
            ElNumber = e;
            VR = vr;
            Name = name;
        }

        string getName(){
            return Name;
        }

        string getVR(){
            return VR;
        }

        void getTag(unsigned int* g,unsigned int* e){
            *g = GroupNumber;
            *e = ElNumber;
        }
    };

    // Maps tag to its name and VR
    map<pair<unsigned int,unsigned int>, Element> tags;

    // Names of all tags
    void makeTag(){
        FILE* f;
        // aux file with tag and its name
        f = fopen("tags.txt", "r");
        unsigned int a, b;           // tag numbers
        string vr = "";     
        char g,e;           // VR values
        char name[100];     // Tag name
        int p = 0;
        while(fscanf(f, "%u,%u,%c%c,%s", &a, &b, &g, &e, name) != EOF){  // file has that many lines
            vr = g+e;
            Element el = Element(a,b, vr, string(name));
            tags[make_pair(a,b)] = el;
            p++;
        }
        printf("Processed %d tags\n", p);
        fclose(f);
    }

    // Returns the element with given tag
    Element getElement(pair<unsigned int,unsigned int> tag){
        return tags[tag];
    }
}