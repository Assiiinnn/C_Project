import json
import subprocess
import os
import sys

def run_tests():
    # Chemins des fichiers
    json_path = os.path.join('tests', 'input.json')
    exe_path = './lru_app'
    if sys.platform == "win32": exe_path = 'lru_app.exe'

    # Vérifications
    if not os.path.exists(json_path):
        print("❌ Erreur: tests/input.json introuvable.")
        sys.exit(1)
    if not os.path.exists(exe_path):
        print("❌ Erreur: lru_app introuvable. Lancez 'make' d'abord.")
        sys.exit(1)

    with open(json_path, 'r') as f:
        data = json.load(f)

    print(f"🚀 Démarrage des tests JSON...")
    
    # Lancement du programme C
    # On lance une seule instance avec une capacité par défaut suffisante ou max
    # Note: Pour ce TP, on relance le programme pour chaque scénario pour gérer la capacité
    
    all_passed = True
    
    for scenario in data['tests']:
        print(f"\n🔹 Scénario: {scenario['name']} (Capacité: {scenario['capacity']})")
        
        # On lance le programme C
        process = subprocess.Popen(
            [exe_path, str(scenario['capacity'])],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        try:
            for op in scenario['operations']:
                cmd = op['op'].upper() # PUT ou GET
                key = op['key']
                
                if cmd == 'PUT':
                    val = op['value']
                    process.stdin.write(f"PUT {key} {val}\n")
                    process.stdin.flush()
                
                elif cmd == 'GET':
                    expected = op['expected']
                    process.stdin.write(f"GET {key}\n")
                    process.stdin.flush()
                    
                    # Lecture de la réponse
                    output = process.stdout.readline().strip()
                    
                    if output == str(expected):
                        print(f"   ✅ GET {key} -> {output}")
                    else:
                        print(f"   ❌ GET {key} -> Attendu {expected}, Reçu '{output}'")
                        all_passed = False
            
            process.terminate()
            
        except Exception as e:
            print(f"   ❌ Erreur technique : {e}")
            process.kill()
            all_passed = False

    if all_passed:
        print("\n✨ TOUS LES TESTS SONT VALIDÉS !")
        sys.exit(0)
    else:
        print("\n💥 ECHEC DES TESTS.")
        sys.exit(1)

if __name__ == "__main__":
    run_tests()
