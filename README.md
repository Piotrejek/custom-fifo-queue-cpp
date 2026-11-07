# Custom FIFO Queue (C++)

Implementacja struktury FIFO jako bufora cyklicznego z dynamiczną alokacją pamięci. Projekt powstał w ramach zajęć z algorytmów i struktur danych. Kładzie nacisk na ręczne zarządzanie pamięcią, zastosowanie "Reguły Trzech" (głęboka kopia) oraz demonstrację różnic między przekazywaniem argumentów przez wartość, wskaźnik i referencję.

## Struktura projektu

```text
.
├── app.cpp         # Kod źródłowy implementujący klasę Queue, interfejs menu oraz dema
├── aisd_Lab5.md    # Wypełnione sprawozdanie / dokumentacja z laboratorium
└── README.md       # Plik informacyjny
```

## Wymagania

Do skompilowania projektu wymagany jest dowolny kompilator obsługujący standard C++11 lub nowszy (np. GCC, Clang, MSVC).

## Jak pobrać kod

Sklonuj repozytorium na swój dysk lokalny za pomocą Git, a następnie przejdź do utworzonego katalogu:

```bash
git clone https://github.com/Piotrejek/custom-fifo-queue-cpp.git
cd custom-fifo-queue-cpp
```

## Jak skompilować

Użyj kompilatora `g++` (lub odpowiednika w używanym środowisku). Zalecane jest włączenie podstawowych flag ostrzeżeń:

```bash
g++ -Wall -Wextra app.cpp -o fifo_queue
```

W przypadku korzystania z Visual Studio, otwórz plik `app.cpp` w nowym projekcie konsolowym C++ i skompiluj z poziomu IDE. W CLion lub VS Code możesz użyć wbudowanych narzędzi budowania lub terminala.

## Jak uruchomić

Po pomyślnej kompilacji w terminalu, uruchom plik wykonywalny:

**Windows:**
```cmd
fifo_queue.exe
```

**Linux / macOS:**
```bash
./fifo_queue
```

Po uruchomieniu program najpierw wykona zautomatyzowane demonstracje (wskaźniki, rekurencja, kopiowanie pamięci), a następnie przejdzie do interaktywnego menu tekstowego, które pozwala na ręczne dodawanie i usuwanie elementów z kolejki.