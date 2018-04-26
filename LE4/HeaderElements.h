using namespace std;

namespace HE{
    class Element{
        int GroupNumber, ElNumber;
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
        Element(int g, int e, string vr = "", string name = ""){
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

        void getTag(int* g, int* e){
            *g = GroupNumber;
            *e = ElNumber;
        }
    };

    // Maps tag to its name and VR
    map<pair<int,int>, Element> tags;

    // Names of all tags
    void makeTag(){
        FILE* f;
        // aux file with tag and its name
        f = fopen("tags.txt", "r");
        int a, b;           // tag numbers
        string vr = "";     
        char g,e;           // VR values
        char name[100];     // Tag name
        for(int i = 0; i < 1274; i++){  // file has that many lines
            fscanf(f, "%d,%d,%c%c,%[^\n]s", &a, &b, &g, &e, name);
            vr = g+e;
            Element el = Element(a,b, vr, string(name));
            tags[make_pair(a,b)] = el;
        }
        fclose(f);
    }

    // Returns the element with given tag
    Element getElement(pair<int,int> tag){
        return tags[tag];
    }
}