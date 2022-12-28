import java.util.Scanner;
public class BTree {
    private static final int T = 2;
        int n;
        boolean leaf;
        int[] keys;
        BTree[] children;

        BTree(boolean leaf) {
            this.leaf = leaf;
            keys = new int[2 * T - 1];
            children = new BTree[2 * T];
        }
    private BTree root;

    public BTree() {
        root = new BTree(true);
    }
    public void insert(int key) {
        BTree r = root;
        if (r.n == 2 * T - 1) {
            BTree s = new BTree(false);
            root = s;
            s.children[0] = r;
            splitChild(s, 0);
            insertNonFull(s, key);
        } else {
            insertNonFull(r, key);
        }
    }
    private void insertNonFull(BTree x, int key) {
        int i = x.n - 1;
        if (x.leaf) {
            while (i >= 0 && key < x.keys[i]) {
                x.keys[i + 1] = x.keys[i];
                i--;
            }
            x.keys[i + 1] = key;
            x.n++;
        } else {
            while (i >= 0 && key < x.keys[i]) {
                i--;
            }
            i++;
            if (x.children[i].n == 2 * T - 1) {
                splitChild(x, i);
                if (key > x.keys[i]) {
                    i++;
                }
            }
            insertNonFull(x.children[i], key);
        }
    }
    private void splitChild(BTree x, int i) {
        BTree y = x.children[i];
        BTree z = new BTree(y.leaf);
        z.n = T - 1;
        System.arraycopy(y.keys, T, z.keys, 0, T - 1);
        if (!y.leaf) {
            System.arraycopy(y.children, T, z.children, 0, T);
        }
        y.n = T - 1;
        for (int j = x.n; j > i; j--) {
            x.children[j + 1] = x.children[j];
        }
        x.children[i + 1] = z;
        for (int j = x.n - 1; j >= i; j--) {
            x.keys[j + 1] = x.keys[j];
        }
        x.keys[i] = y.keys[T - 1];
        x.n++;
    }
    private void traverse(BTree x) {
        for (int i = 0; i < x.n; i++) {
            if (!x.leaf) {
                traverse(x.children[i]);
            }
            System.out.print(x.keys[i] + " ");
        }
        if (!x.leaf) {
            traverse(x.children[x.n]);
        }
    }
    public static void main(String[] args) {
        BTree tree = new BTree();
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("Enter a key to insert (enter 'q' to quit): ");
            String input = scanner.nextLine();
            if (input.equals("q")) {
                break;
            }
            int key = Integer.parseInt(input);
            tree.insert(key);
            System.out.print("Inorder traversal: ");
            tree.traverse(tree.root);
            System.out.println();
        }
    }
}
