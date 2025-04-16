def caesar_cipher(text, shift, operation):
    result = ""
    # Define the alphabet (both lowercase and uppercase)
    alphabet_lower = 'abcdefghijklmnopqrstuvwxyz'
    alphabet_upper = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    
    # Adjust shift for decryption
    if operation == "decrypt":
        shift = -shift
    
    for char in text:
        if char in alphabet_lower:
            # Find the position in the alphabet
            position = alphabet_lower.index(char)
            # Calculate new position with wrapping
            new_position = (position + shift) % 26
            # Add the new character to the result
            result += alphabet_lower[new_position]
        elif char in alphabet_upper:
            position = alphabet_upper.index(char)
            new_position = (position + shift) % 26
            result += alphabet_upper[new_position]
        else:
            # Keep non-alphabetic characters unchanged
            result += char
    
    return result

def main():
    print("Welcome to the August Cipher Program")
    print("------------------------------------")
    
    while True:
        # Ask for operation type
        operation = input("Would you like to encrypt or decrypt? (encrypt/decrypt): ").lower()
        if operation not in ["encrypt", "decrypt"]:
            print("Invalid option. Please enter 'encrypt' or 'decrypt'.")
            continue
        
        # Get the message
        text = input("Enter your message: ")
        
        # Get the shift key
        try:
            shift = int(input("Enter the key (a number between 1-25): "))
            if not 1 <= shift <= 25:
                print("Key must be between 1 and 25. Using default key of 3.")
                shift = 3
        except ValueError:
            print("Invalid key. Using default key of 3.")
            shift = 3
        
        # Process the text
        result = caesar_cipher(text, shift, operation)
        
        # Display the result
        print(f"\nYour {operation}ed message is:")
        print(result)
        print()
        
        # Ask if the user wants to continue
        again = input("Would you like to process another message? (yes/no): ").lower()
        if again != "yes":
            break
    
    print("Thank you for using the August Cipher Program!")

if __name__ == "__main__":
    main()
    
