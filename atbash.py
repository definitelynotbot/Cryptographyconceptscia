def atbash_cipher(text, mode):
    result = ""
    for char in text:
        if char.isalpha():
            # Determine if uppercase or lowercase
            if char.isupper():
                # For uppercase: Z - (char - A)
                result += chr(90 - (ord(char) - 65))
            else:
                # For lowercase: z - (char - a)
                result += chr(122 - (ord(char) - 97))
        else:
            # Keep non-alphabetic characters unchanged
            result += char
    
    return result

def main():
    # Get user input
    message = input("Enter the message: ")
    
    while True:
        mode = input("Enter 'encrypt' for encryption or 'decrypt' for decryption: ").lower()
        if mode in ["encrypt", "decrypt"]:
            break
        else:
            print("Please enter either 'encrypt' or 'decrypt'.")
    
    # Process the message (Atbash is its own inverse, so encrypt/decrypt are the same)
    result = atbash_cipher(message, mode)
    
    # Display the result
    print(f"\nOriginal message: {message}")
    print(f"Mode: {mode}")
    print(f"Result: {result}")

if __name__ == "__main__":
    main()
