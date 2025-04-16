def caesar_cipher(text, key, mode):
    result = ""
    # Handle both uppercase and lowercase letters
    for char in text:
        if char.isalpha():
            # Determine the ASCII offset (65 for uppercase, 97 for lowercase)
            ascii_offset = 65 if char.isupper() else 97
            
            # Apply encryption or decryption
            if mode == "encrypt":
                # For encryption: (position + key) % 26
                shifted = (ord(char) - ascii_offset + key) % 26
            else:
                # For decryption: (position - key) % 26
                shifted = (ord(char) - ascii_offset - key) % 26
            
            # Convert back to character and add to result
            result += chr(shifted + ascii_offset)
        else:
            # Keep non-alphabetic characters unchanged
            result += char
    
    return result

def main():
    # Get user input
    message = input("Enter the message: ")
    
    while True:
        try:
            key = int(input("Enter the key (0-25): "))
            if 0 <= key <= 25:
                break
            else:
                print("Key must be between 0 and 25.")
        except ValueError:
            print("Please enter a valid integer.")
    
    while True:
        mode = input("Enter 'encrypt' for encryption or 'decrypt' for decryption: ").lower()
        if mode in ["encrypt", "decrypt"]:
            break
        else:
            print("Please enter either 'encrypt' or 'decrypt'.")
    
    # Process the message
    result = caesar_cipher(message, key, mode)
    
    # Display the result
    print(f"\nOriginal message: {message}")
    print(f"Key: {key}")
    print(f"Mode: {mode}")
    print(f"Result: {result}")

if __name__ == "__main__":
    main()


